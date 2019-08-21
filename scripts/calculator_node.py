#!/usr/bin/env python

from robert_v_sandbox.srv import *
import rospy

"""
Created on 21 August 2019
@author: Robert Valner
"""

def add_service(req):
    """
    This is a service routine that adds two numbers.

    :param req: Request portion of the AddTwoNumbers service message. 
    :type req: AddTwoNumers::Request type. 
    :returns: Returns the AddTwoNumers::Response type. 
    """ 
    print "Returning [%s + %s = %s]"%(req.num_a, req.num_b, (req.num_a + req.num_b))
    return AddTwoNumbersResponse(req.num_a + req.num_b)

def calculator_main():
    rospy.init_node('calculator_node_py')
    s = rospy.Service('add_two_numbers', AddTwoNumbers, add_service)
    print "Ready to crunch some numbers!"
    rospy.spin()

if __name__ == "__main__":
    calculator_main()