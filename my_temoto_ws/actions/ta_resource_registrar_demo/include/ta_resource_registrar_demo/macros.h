
#ifndef ta_resource_registrar_demo_MACROS_H
#define ta_resource_registrar_demo_MACROS_H

#define GET_PARAMETER(name, type) boost::any_cast<type>(getUmrfPtr()->getInputParameters().getParameter(name).getData())
#define SET_PARAMETER(name, type, value) getUmrfPtr()->getOutputParametersNc().setParameter(name, type, boost::any(value))

#endif
