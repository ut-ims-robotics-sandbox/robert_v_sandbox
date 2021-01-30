# trajectory_recorder
The trajectory recorder listens to the [sensor_msgs/JointState](http://docs.ros.org/en/melodic/api/sensor_msgs/html/msg/JointState.html) topic and assembles a [trajectory_msgs/JointTrajectory](http://docs.ros.org/en/api/trajectory_msgs/html/msg/JointTrajectory.html) message from the joint_state messages.

## Usage
``` bash
rosrun trajectory_recorder trajectory_recorder
```
to remap the joint_state topic:
``` bash
rosrun trajectory_recorder trajectory_recorder joint_states:=<NEW_TOPIC_NAME>
```

The recorder can be started and stopped via ROS service. Previously recorded trajectory is overwritten when the recorder is started.

Start recording:
``` bash
rosservice call /control_trajectory_recorder "recorder_action: 0" 
```
Stop recording
``` bash
rosservice call /control_trajectory_recorder "recorder_action: 1" 
```

The recorded trajectory can be extracted via:
``` bash
rosservice call /get_recorded_trajectory "{}"
``` 