#!/usr/bin/env python

from robert_v_sandbox.srv import *
import rospy

def add_service(req):
    print "Returning [%s + %s = %s]"%(req.num_a, req.num_b, (req.num_a + req.num_b))
    return AddTwoNumbersResponse(req.num_a + req.num_b)

def calculator_main():
    rospy.init_node('calculator_node_py')
    s = rospy.Service('add_two_numbers', AddTwoNumbers, add_service)
    print "Ready to crunch some numbers!"
    rospy.spin()

if __name__ == "__main__":
    calculator_main()