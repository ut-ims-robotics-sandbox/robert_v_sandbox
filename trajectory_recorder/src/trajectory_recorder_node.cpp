#include "trajectory_recorder/trajectory_recorder.h"
#include "ros/ros.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "trajectory_recorder_node");

  trajectory_recorder::TrajectoryRecorder tr("joint_states", 20, true);

  /*
   * Set up the spinner
   */
  ros::AsyncSpinner spinner(0);
  spinner.start();
  ros::waitForShutdown();

  return 0;
}