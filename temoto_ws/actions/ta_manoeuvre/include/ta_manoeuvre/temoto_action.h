
#ifndef ta_manoeuvre_TEMOTO_ACTION_H
#define ta_manoeuvre_TEMOTO_ACTION_H

/* REQUIRED BY TEMOTO */
#include "temoto_core/common/base_subsystem.h"
#include "temoto_action_engine/action_base.h"
#include "temoto_action_engine/temoto_error.h"
#include "temoto_action_engine/messaging.h"

/**
 * @brief Class that integrates TeMoto Base Subsystem specific and Action Engine specific codebases.
 * 
 */
class TemotoAction : public ActionBase, public temoto_core::BaseSubsystem
{
public:
  TemotoAction()
  : BaseSubsystem("action_engine", temoto_core::error::Subsystem::TASK, "DEFINED_LATER", "actions")
  {}

  /**
   * @brief Get the Name of the action
   * 
   * @return const std::string& 
   */
  const std::string& getName()
  {
    return getUmrfPtr()->getName();
  }

  /**
   * @brief Wraps the executeTemotoAction and converts TeMoto specific errors to action engine errors.
   * 
   */
  void executeAction()
  {
    try
    {
      /* 
       * Assign the class name. This cannot be done in constructor because class loader works
       * only with default constructors.
       */ 
      class_name_ = getUmrfPtr()->getName();
      executeTemotoAction();
    }
    catch(temoto_core::error::ErrorStack e)
    {
      /*
       * TODO: Do something with TeMoto errors.
       */
      std::cout << e << std::endl;
    }
    catch(const std::exception& e)
    {
      throw CREATE_TEMOTO_ERROR_STACK(e.what());
    }
    catch(...)
    {
      throw CREATE_TEMOTO_ERROR_STACK("Caught an unhandled exception");
    }
  }

/**
 * @brief Virtual function that has to be implemented by an action.
 * 
 */
virtual void executeTemotoAction() = 0;
};

#endif
