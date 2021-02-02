#ifndef TEMOTO_ACTION_ENGINE__ACTION_BASE_H
#define TEMOTO_ACTION_ENGINE__ACTION_BASE_H

#include <memory>
#include <iostream>
#include <vector>
#include <boost/any.hpp>

typedef std::vector<boost::any> MyData;
typedef std::shared_ptr<MyData> MyDataSharedPtr;
typedef int AnyType;

class PluginBase
{
public:

  void setData(const MyData& data)
  {
    for (const auto& d : data)
    {
      data_.emplace_back(boost::any_cast<AnyType>(d));
    }
  }

  const MyData& getData()
  {
    return data_;
  }

  virtual void processData() = 0;

  virtual ~PluginBase(){};

  MyData data_;
};
#endif