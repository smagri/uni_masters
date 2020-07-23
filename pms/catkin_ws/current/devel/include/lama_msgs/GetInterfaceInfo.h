// Generated by gencpp from file lama_msgs/GetInterfaceInfo.msg
// DO NOT EDIT!


#ifndef LAMA_MSGS_MESSAGE_GETINTERFACEINFO_H
#define LAMA_MSGS_MESSAGE_GETINTERFACEINFO_H

#include <ros/service_traits.h>


#include <lama_msgs/GetInterfaceInfoRequest.h>
#include <lama_msgs/GetInterfaceInfoResponse.h>


namespace lama_msgs
{

struct GetInterfaceInfo
{

typedef GetInterfaceInfoRequest Request;
typedef GetInterfaceInfoResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetInterfaceInfo
} // namespace lama_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::lama_msgs::GetInterfaceInfo > {
  static const char* value()
  {
    return "88018d5bbc756bb20b9d16e277b1cdc7";
  }

  static const char* value(const ::lama_msgs::GetInterfaceInfo&) { return value(); }
};

template<>
struct DataType< ::lama_msgs::GetInterfaceInfo > {
  static const char* value()
  {
    return "lama_msgs/GetInterfaceInfo";
  }

  static const char* value(const ::lama_msgs::GetInterfaceInfo&) { return value(); }
};


// service_traits::MD5Sum< ::lama_msgs::GetInterfaceInfoRequest> should match 
// service_traits::MD5Sum< ::lama_msgs::GetInterfaceInfo > 
template<>
struct MD5Sum< ::lama_msgs::GetInterfaceInfoRequest>
{
  static const char* value()
  {
    return MD5Sum< ::lama_msgs::GetInterfaceInfo >::value();
  }
  static const char* value(const ::lama_msgs::GetInterfaceInfoRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::lama_msgs::GetInterfaceInfoRequest> should match 
// service_traits::DataType< ::lama_msgs::GetInterfaceInfo > 
template<>
struct DataType< ::lama_msgs::GetInterfaceInfoRequest>
{
  static const char* value()
  {
    return DataType< ::lama_msgs::GetInterfaceInfo >::value();
  }
  static const char* value(const ::lama_msgs::GetInterfaceInfoRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::lama_msgs::GetInterfaceInfoResponse> should match 
// service_traits::MD5Sum< ::lama_msgs::GetInterfaceInfo > 
template<>
struct MD5Sum< ::lama_msgs::GetInterfaceInfoResponse>
{
  static const char* value()
  {
    return MD5Sum< ::lama_msgs::GetInterfaceInfo >::value();
  }
  static const char* value(const ::lama_msgs::GetInterfaceInfoResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::lama_msgs::GetInterfaceInfoResponse> should match 
// service_traits::DataType< ::lama_msgs::GetInterfaceInfo > 
template<>
struct DataType< ::lama_msgs::GetInterfaceInfoResponse>
{
  static const char* value()
  {
    return DataType< ::lama_msgs::GetInterfaceInfo >::value();
  }
  static const char* value(const ::lama_msgs::GetInterfaceInfoResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // LAMA_MSGS_MESSAGE_GETINTERFACEINFO_H
