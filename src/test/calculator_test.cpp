#include <ros/ros.h>
#include <gtest/gtest.h>
#include "robert_v_sandbox/AddTwoNumbers.h"

/*
 * Tests the adding functionality of the calculator node
 */
TEST(TestSuite, add_test)
{
  ros::NodeHandle nh;
  ros::ServiceClient scl = nh.serviceClient<robert_v_sandbox::AddTwoNumbers>("add_two_numbers");

  // Compose the service message
  robert_v_sandbox::AddTwoNumbers srv_msg;
  srv_msg.request.num_a = 34;
  srv_msg.request.num_b = 5;

  // The result we are expecting to receive from the service call
  double expected_result = srv_msg.request.num_a + srv_msg.request.num_b;

  // Invoke the service call
  if (scl.call(srv_msg))
  {
    // Check if the response is equal to the expected result
    EXPECT_EQ(srv_msg.response.result, expected_result) << "Expected " << expected_result << " but got " << srv_msg.response.result;
  }
  else
  {
    // Assert false if the client was not able to reach the server
    ASSERT_TRUE(false) << "Could not reach the 'add_two_numbers' server";
  }
} 

/*
 * Main
 */
int main(int argc, char **argv)
{
  // Initialize the gtes
  testing::InitGoogleTest(&argc, argv);

  // Set up the test node 
  ros::init(argc, argv, "TestSuite");

  // Run the tests
  return RUN_ALL_TESTS();
}