#include "ros/ros.h"
#include "robert_v_sandbox/my_math_operators.h"
#include "robert_v_sandbox/AddTwoNumbers.h"

/*
 * Add server service routine
 */ 
bool addService( robert_v_sandbox::AddTwoNumbers::Request &req
               , robert_v_sandbox::AddTwoNumbers::Response &res)
{
  res.result = math_operators::add(req.num_a, req.num_b);
  ROS_INFO_STREAM("Adding numbers " << req.num_a << " and " << req.num_b << ". Result = " << res.result);
  return true;
}               

/*
 * Main
 */ 
int main(int argc, char** argv)
{
  ros::init(argc, argv, "calculator_node");
  ros::NodeHandle nh;

  ros::ServiceServer add_server = nh.advertiseService("add_two_numbers", addService);
  ROS_INFO("Ready to crunch some numbers!");
  ros::spin();

  return 0;
}