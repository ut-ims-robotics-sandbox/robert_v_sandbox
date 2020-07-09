
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
#include "ta_survey/temoto_action.h"
#include "ta_survey/macros.h"

/* 
 * ACTION IMPLEMENTATION of TaSurvey 
 */
class TaSurvey : public TemotoAction
{
public:

// Constructor. REQUIRED BY TEMOTO
TaSurvey()
{
  std::cout << __func__ << " constructed\n";
}

// REQUIRED BY TEMOTO
void executeTemotoAction()
{
  // Input parameters
  std::string survey_type = GET_PARAMETER("survey_type", std::string);

  /* * * * * * * * * * * * * * 
   *                          
   * ===> YOUR CODE HERE <===
   *                          
   * * * * * * * * * * * * * */

}

// Destructor
~TaSurvey()
{
  TEMOTO_INFO("Action instance destructed");
}

}; // TaSurvey class

/* REQUIRED BY CLASS LOADER */
CLASS_LOADER_REGISTER_CLASS(TaSurvey, ActionBase);
