#include "trajectory_recorder/trajectory_recorder.h"
#include "iostream"

namespace trajectory_recorder
{

TrajectoryRecorder::TrajectoryRecorder(const std::string& joint_states_topic, float frequency, bool enable_services)
: state_(State::idle)
{
  /*
   * Subscribe to joint_states topic
   */ 
  if (!joint_states_topic.empty())
  {
    joint_states_sub_ = nh_.subscribe(joint_states_topic, 1, &TrajectoryRecorder::jointStatesCallback, this);
  }
  else
  {
    ROS_ERROR_STREAM("The joint states topic should not be an empty string");
    state_ = State::error;
    return;
  }
  
  /*
   * Check the desired frequency
   */
  if (!setRecordingFrequency(frequency))
  {
    state_ = State::error;
    return;
  }

  /*
   * Enable the ROS servers to control the trajectory recorder
   */
  if (enable_services)
  {
    recorder_control_server_ = nh_.advertiseService("control_trajectory_recorder"
    , &TrajectoryRecorder::trajectoryRecorderControlCb
    , this);

    get_trajectory_server_ = nh_.advertiseService("get_recorded_trajectory"
    , &TrajectoryRecorder::getRecordedTrajectoryCb
    , this);
  } 
  
  ROS_INFO_STREAM("The trajectory recorder is initialized");
}

void TrajectoryRecorder::startRecordingTrajectory()
{
  std::lock_guard<std::mutex> state_rw_guard(state_rw_mutex_);

  // Check the state of recorder
  if (state_ == State::error)
  {
    ROS_ERROR_STREAM("Cannot record trajectory because the recorder is in error state");
    return;
  }

  // Clear the trajectory
  ROS_INFO_STREAM("Started recording the trajectory");
  recorded_trajectory_ = trajectory_msgs::JointTrajectory();
  state_ = State::recording;
}

void TrajectoryRecorder::stopRecordingTrajectory()
{
  std::lock_guard<std::mutex> state_rw_guard(state_rw_mutex_);

  // Check the state of recorder
  if (state_ == State::error)
  {
    ROS_ERROR_STREAM("Cannot stop recording the trajectory because the recorder is in error state");
    return;
  }

  ROS_INFO_STREAM("Stopped recording the trajectory");
  state_ = State::idle;
}

trajectory_msgs::JointTrajectory TrajectoryRecorder::getRecordedTrajectory()
{
  return recorded_trajectory_;
}

float TrajectoryRecorder::getRecordingFrequency() const
{
  std::lock_guard<std::mutex> frequency_rw_guard(frequency_rw_mutex_);
  return frequency_;
}

bool TrajectoryRecorder::setRecordingFrequency(float frequency)
{
  std::lock_guard<std::mutex> frequency_rw_guard(frequency_rw_mutex_);
  if (isFrequencyValid(frequency))
  {
    frequency_ = frequency;
    return true;
  }
  else
  {
    ROS_ERROR_STREAM("The frequency must be a positive number");
    return false;
  }
}

void TrajectoryRecorder::smoothenRecordedTrajectory()
{
  
}

bool TrajectoryRecorder::isFrequencyValid(const float& frequency)
{
  return (frequency > 0);
}

void TrajectoryRecorder::jointStatesCallback(const sensor_msgs::JointState& msg)
{
  std::lock_guard<std::mutex> state_rw_guard(state_rw_mutex_);
  switch(state_)
  {
    case State::idle:
    {
      // Do nothing
    }
    break;

    case State::recording:
    {
      double time_diff_sec = ros::Time::now().toSec() - time_from_last_point_.toSec();
      if ( time_diff_sec >= 1/getRecordingFrequency())
      {
        addTrajectoryPoint(msg);
      }
    }
    break;

    case State::error:
    {
      // Do nothing
    }
    break;
  }
}

void TrajectoryRecorder::addTrajectoryPoint(const sensor_msgs::JointState& msg)
{
  if (recorded_trajectory_.joint_names.empty())
  {
    recorded_trajectory_.joint_names = msg.name;
  }

  // Add the joint state msg as a new trajectory point
  trajectory_msgs::JointTrajectoryPoint trajectory_point;
  trajectory_point.positions = msg.position;
  trajectory_point.velocities = msg.velocity;
  trajectory_point.accelerations = msg.effort;
  recorded_trajectory_.points.push_back(trajectory_point);

  time_from_last_point_ = ros::Time::now();
}

bool TrajectoryRecorder::trajectoryRecorderControlCb(TrajectoryRecorderControl::Request& req
, TrajectoryRecorderControl::Response& res)
{
  if (req.recorder_action == req.START)
  {
    startRecordingTrajectory();
    res.response_message = "Started recording the trajectory";
  }
  else if (req.recorder_action == req.STOP)
  {
    stopRecordingTrajectory();
    res.response_message = "Stopped recording the trajectory";
  }
  else
  {
    res.response_message = "Trajectory recorder received an unknown command";
    ROS_ERROR_STREAM(res.response_message);
  }
  return true;
}

bool TrajectoryRecorder::getRecordedTrajectoryCb(GetRecordedTrajectory::Request& req
, GetRecordedTrajectory::Response& res)
{
  std::lock_guard<std::mutex> state_rw_guard(state_rw_mutex_);

  // Check the state of recorder
  if (state_ == State::error)
  {
    res.response_message = "Cannot return the trajectory because the recorder is in error state";
    ROS_ERROR_STREAM(res.response_message);
  }
  else if (state_ == State::recording)
  {
    res.response_message = "Cannot return the trajectory because the recording is still in process";
    ROS_ERROR_STREAM(res.response_message);
  }
  else
  {
    res.response_message = "ok";
    res.trajectory = recorded_trajectory_;
  }
  return true;
}

} // trajectory_recorder namespace