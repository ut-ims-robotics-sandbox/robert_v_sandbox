#ifndef ROBERT_V_SANDBOX__CALCULATOR_NODELET_H
#define ROBERT_V_SANDBOX__CALCULATOR_NODELET_H

#include <nodelet/nodelet.h>
#include "ros/ros.h"
#include "robert_v_sandbox/AddTwoNumbers.h"

/**
 * @brief Nodelet version of the calculator node
 * 
 */
class CalculatorNodelet : public nodelet::Nodelet
{
public:
  /**
   * @brief Function that every nodelet has to implement
   * 
   */
  virtual void onInit();

private:

  /**
   * @brief Service routine forthe add service
   * 
   * @param req Request portion of the service 
   * @param res Respose portion of the service
   */
  bool addService( robert_v_sandbox::AddTwoNumbers::Request &req
                 , robert_v_sandbox::AddTwoNumbers::Response &res);

  /// Nodehandle for ROS communication
  ros::NodeHandle nh_;

  /// Server for handling adding functionality
  ros::ServiceServer add_server_;
};

#endif