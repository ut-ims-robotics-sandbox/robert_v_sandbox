
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
#include "ta_manoeuvre/temoto_action.h"
#include "ta_manoeuvre/macros.h"

/* 
 * ACTION IMPLEMENTATION of TaManoeuvre 
 */
class TaManoeuvre : public TemotoAction
{
public:

// Constructor. REQUIRED BY TEMOTO
TaManoeuvre()
{
  std::cout << __func__ << " constructed\n";
}

// REQUIRED BY TEMOTO
void executeTemotoAction()
{
  // Input parameters
  std::string direction = GET_PARAMETER("direction", std::string);
  double distance_amount = GET_PARAMETER("distance::amount", double);
  std::string distance_unit = GET_PARAMETER("distance::unit", std::string);
  std::string verb = GET_PARAMETER("verb", std::string);

  /* * * * * * * * * * * * * * 
   *                          
   * ===> YOUR CODE HERE <===
   *                          
   * * * * * * * * * * * * * */

}

// Destructor
~TaManoeuvre()
{
  TEMOTO_INFO("Action instance destructed");
}

}; // TaManoeuvre class

/* REQUIRED BY CLASS LOADER */
CLASS_LOADER_REGISTER_CLASS(TaManoeuvre, ActionBase);
