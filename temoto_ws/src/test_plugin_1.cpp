#include <class_loader/class_loader.hpp>
#include "temoto_ws/plugin_base.h"
#include <iostream>

class TestPlugin1 : public PluginBase
{
public:

// Constructor. REQUIRED BY TEMOTO
TestPlugin1()
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
  data_.emplace_back(4);
  data_.emplace_back(5);

  std::cout << __func__ << ": finished adding data. The final result is:" << std::endl;
  for (const auto& d : getData())
  {
    std::cout << boost::any_cast<AnyType>(d) << std::endl;
  }
}

// Destructor
~TestPlugin1()
{
 std::cout << "TestPlugin1 instance destructed" << std::endl;
}

}; // TestPlugin1 class

class PluginDataPreStorage1 : public PluginBase
{
public:
  PluginDataPreStorage1()
  {
    std::cout << __func__ << " constructed\n";
  }

  virtual void processData()
  {
  }

  ~PluginDataPreStorage1()
  {
  std::cout << "PluginDataPreStorage1 instance destructed" << std::endl;
  }
};

/* REQUIRED BY CLASS LOADER */
CLASS_LOADER_REGISTER_CLASS(TestPlugin1, PluginBase);
CLASS_LOADER_REGISTER_CLASS(PluginDataPreStorage1, PluginBase);
