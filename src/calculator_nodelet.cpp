#include "robert_v_sandbox/calculator_nodelet.h"
#include <pluginlib/class_list_macros.h>
#include "robert_v_sandbox/my_math_operators.h"

PLUGINLIB_EXPORT_CLASS(CalculatorNodelet, nodelet::Nodelet)

// onInit
void CalculatorNodelet::onInit()
{
  nh_ = getNodeHandle();
  add_server_ = nh_.advertiseService("add_two_numbers", &CalculatorNodelet::addService, this);
  NODELET_INFO("Ready to crunch some numbers!");
}

// addService
bool CalculatorNodelet::addService( robert_v_sandbox::AddTwoNumbers::Request &req
                                  , robert_v_sandbox::AddTwoNumbers::Response &res)
{
  res.result = math_operators::add(req.num_a, req.num_b);
  ROS_INFO_STREAM("Adding numbers " << req.num_a << " and " << req.num_b << ". Result = " << res.result);
  return true;
}