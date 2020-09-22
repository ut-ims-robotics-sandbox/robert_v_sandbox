
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *
 *  The basis of this file has been automatically generated
 *  by the TeMoto action package generator. Modify this file
 *  as you wish but please note:
 *
 *    WE HIGHLIY RECOMMEND TO REFER TO THE TeMoto ACTION
 *    IMPLEMENTATION TUTORIAL IF YOU ARE UNFAMILIAR WITH
 *    THE PROCESS OF CREATING CUSTOM TeMoto ACTION PACKAGES
 *    
 *  because there are plenty of components that should not be
 *  modified or which do not make sence at the first glance.
 *
 *  See TeMoto documentation & tutorials at: 
 *    https://temoto-telerobotics.github.io
 *
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

/* REQUIRED BY TEMOTO */
#include <class_loader/class_loader.hpp>
#include "ta_rr_pipe_example/temoto_action.h"
#include "ta_rr_pipe_example/macros.h"
#include "temoto_component_manager/component_manager_interface.h"

/* 
 * ACTION IMPLEMENTATION of TaRrPipeExample 
 */
class TaRrPipeExample : public TemotoAction
{
public:

// Constructor. REQUIRED BY TEMOTO
TaRrPipeExample()
{
  std::cout << __func__ << " constructed\n";
}

// REQUIRED BY TEMOTO
void executeTemotoAction()
{
  cmi_.initialize(this);

  /*
   * Start the test pipe, a single resource which internally combines 3 resources (components). 
   * Each component subscribes to a std_msgs::string topic, appends to the incoming string
   * message and publishes the appended string on a different topic - thus forming a pipe where
   * the last segment of the pipe outputs the final assembled string.
   */
  TEMOTO_INFO_STREAM("Starting the test pipe ...");
  temoto_core::TopicContainer pipe_topics = cmi_.startPipe("test_pipe");

  TEMOTO_INFO_STREAM("The pipe outputs its data on following topic types:");
  for (const auto& pipe_topic : pipe_topics.getOutputTopics())
  {
    TEMOTO_INFO_STREAM(pipe_topic.first << " at " << pipe_topic.second);
  }

  /*
   * Now it is up to the user/action-developer to do something with the pipe topics 
   */
}

// Destructor
~TaRrPipeExample()
{
  TEMOTO_INFO("Action instance destructed");
}

private:
  temoto_component_manager::ComponentManagerInterface<TaRrPipeExample> cmi_;

}; // TaRrPipeExample class

/* REQUIRED BY CLASS LOADER */
CLASS_LOADER_REGISTER_CLASS(TaRrPipeExample, ActionBase);
