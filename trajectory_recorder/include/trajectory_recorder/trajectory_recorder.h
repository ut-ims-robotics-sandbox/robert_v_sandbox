#ifndef TRAJECTORY_RECORDER__TRAJECTORY_RECORDER_H
#define TRAJECTORY_RECORDER__TRAJECTORY_RECORDER_H

#include <string>
#include <vector>

class TrajectoryRecorder
{
public:

  enum class state
  {
    idle,
    recording,
    error
  };

  TrajectoryRecorder(const std::string& joint_states_topic);

  void recordTrajectory();

  void stopRecording();

  const std::vector<int> getRecordedTrajectory();

  void setRecordingFrequency(unsigned int frequency);

private:

  void smoothenRecordedTrajectory();

  unsigned int frequency_;
};

#endif