#include <class_loader/class_loader.hpp>
#include <boost/shared_ptr.hpp>
#include <string>
#include "temoto_ws/plugin_base.h"

int main(int argc, char** argv)
{
  std::string plugin_path_1 = "/home/robert/catkin_workspaces/sandbox_ws/src/temoto_ws/temoto_ws/lib/libtest_plugin_1.so";
  std::string plugin_name_1 = "TestPlugin1";

  std::string plugin_path_2 = "/home/robert/catkin_workspaces/sandbox_ws/src/temoto_ws/temoto_ws/lib/libtest_plugin_2.so";
  std::string plugin_name_2 = "TestPlugin2";

  MyData data;

  data.emplace_back(1);
  data.emplace_back(2);
  data.emplace_back(3);

  {
    // Prestore
    class_loader::ClassLoader class_loader_1(plugin_path_1, false);
    boost::shared_ptr<PluginBase> plugin_prestore_instance = class_loader_1.createInstance<PluginBase>("PluginDataPreStorage1");
    plugin_prestore_instance->setData(data);

    boost::shared_ptr<PluginBase> test_plugin_1_instance = class_loader_1.createInstance<PluginBase>(plugin_name_1);
    test_plugin_1_instance->setData(plugin_prestore_instance->getData());
    plugin_prestore_instance.reset();
    test_plugin_1_instance->processData();

    // Prestore
    class_loader::ClassLoader class_loader_2(plugin_path_2, false);
    boost::shared_ptr<PluginBase> plugin_prestore_instance_2 = class_loader_2.createInstance<PluginBase>("PluginDataPreStorage2");
    plugin_prestore_instance_2->setData(test_plugin_1_instance->getData());
    test_plugin_1_instance.reset();

    boost::shared_ptr<PluginBase> test_plugin_2_instance = class_loader_2.createInstance<PluginBase>(plugin_name_2);
    test_plugin_2_instance->setData(plugin_prestore_instance_2->getData());
    plugin_prestore_instance_2.reset();
    test_plugin_2_instance->processData();    
  }

  std::cout << "das end" << std::endl;

  return 0;
}