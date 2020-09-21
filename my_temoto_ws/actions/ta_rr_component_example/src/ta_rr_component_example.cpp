
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
#include "ta_rr_component_example/temoto_action.h"
#include "ta_rr_component_example/macros.h"
#include "temoto_component_manager/component_manager_interface.h"

/* 
 * ACTION IMPLEMENTATION of TaRrComponentExample 
 */
class TaRrComponentExample : public TemotoAction
{
public:

// Constructor. REQUIRED BY TEMOTO
TaRrComponentExample()
{
  std::cout << __func__ << " constructed\n";
}

// REQUIRED BY TEMOTO
void executeTemotoAction()
{
  cmi_.initialize(this);
  
  /*
   * Start a component which publishes two topics with 'std::string' message type.
   */
  TEMOTO_INFO_STREAM("Starting a component ...");
  temoto_core::TopicContainer component_topics = cmi_.startComponent("cs_test_0");

  TEMOTO_INFO_STREAM("The component outputs its data on following topic types:");
  for (const auto& component_topic : component_topics.getOutputTopics())
  {
    TEMOTO_INFO_STREAM(component_topic.first << " at " << component_topic.second);
  }
}

// Destructor
~TaRrComponentExample()
{
  TEMOTO_INFO("Action instance destructed");
}

private:
  temoto_component_manager::ComponentManagerInterface<TaRrComponentExample> cmi_;

}; // TaRrComponentExample class

/* REQUIRED BY CLASS LOADER */
CLASS_LOADER_REGISTER_CLASS(TaRrComponentExample, ActionBase);
