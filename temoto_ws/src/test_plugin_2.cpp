#include <class_loader/class_loader.hpp>
#include "temoto_ws/plugin_base.h"
#include <iostream>

class TestPlugin2 : public PluginBase
{
public:

// Constructor. REQUIRED BY TEMOTO
TestPlugin2()
{
  std::cout << __func__ << " constructed\n";
}

virtual void processData()
{
  std::cout << __func__ << ": processing the data. Got:" << std::endl;
  for (const auto& d : getData())
  {
    std::cout << boost::any_cast<AnyType>(d) << std::endl;
  }

  std::cout << __func__ << ": adding data ..." << std::endl;
  data_.emplace_back(6);
  data_.emplace_back(7);

  std::cout << __func__ << ": finished adding data. The final result is:" << std::endl;
  for (const auto& d : getData())
  {
    std::cout << boost::any_cast<AnyType>(d) << std::endl;
  }
}

// Destructor
~TestPlugin2()
{
 std::cout << "TestPlugin2 instance destructed" << std::endl;
}

}; // TestPlugin2 class

class PluginDataPreStorage2 : public PluginBase
{
public:
  PluginDataPreStorage2()
  {
    std::cout << __func__ << " constructed\n";
  }

  virtual void processData()
  {
  }

  ~PluginDataPreStorage2()
  {
  std::cout << "PluginDataPreStorage2 instance destructed" << std::endl;
  }
};

/* REQUIRED BY CLASS LOADER */
CLASS_LOADER_REGISTER_CLASS(TestPlugin2, PluginBase);
CLASS_LOADER_REGISTER_CLASS(PluginDataPreStorage2, PluginBase);
