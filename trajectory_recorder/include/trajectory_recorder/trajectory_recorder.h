#ifndef TRAJECTORY_RECORDER__TRAJECTORY_RECORDER_H
#define TRAJECTORY_RECORDER__TRAJECTORY_RECORDER_H

#include <string>
#include <vector>
#include <mutex>
#include "ros/ros.h"
#include "sensor_msgs/JointState.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "trajectory_recorder/TrajectoryRecorderControl.h"
#include "trajectory_recorder/GetRecordedTrajectory.h"

namespace trajectory_recorder
{

class TrajectoryRecorder
{
public:

  enum class State
  {
    idle,
    recording,
    error
  };

  TrajectoryRecorder(const std::string& joint_states_topic, float frequency = 20, bool enable_services = true);

  void startRecordingTrajectory();

  void stopRecordingTrajectory();

  float getRecordingFrequency() const;

  trajectory_msgs::JointTrajectory getRecordedTrajectory();

  bool setRecordingFrequency(float frequency);

private:

  void smoothenRecordedTrajectory();

  bool isFrequencyValid(const float& frequency);

  void jointStatesCallback(const sensor_msgs::JointState& msg);

  void addTrajectoryPoint(const sensor_msgs::JointState& msg);

  bool trajectoryRecorderControlCb(TrajectoryRecorderControl::Request& req
  , TrajectoryRecorderControl::Response& res);

  bool getRecordedTrajectoryCb(GetRecordedTrajectory::Request& req
  , GetRecordedTrajectory::Response& res);

  ros::NodeHandle nh_;
  ros::Subscriber joint_states_sub_;
  ros::ServiceServer recorder_control_server_;
  ros::ServiceServer get_trajectory_server_;
  ros::Time time_from_last_point_;
  ros::Time recording_start_time_;

  State state_;
  float frequency_;
  trajectory_msgs::JointTrajectory recorded_trajectory_;
  mutable std::mutex frequency_rw_mutex_;
  mutable std::mutex state_rw_mutex_;
};

} // trajectory_recorder namespace
#endif