// Generated by gencpp from file a3_help/RequestGoalResponse.msg
// DO NOT EDIT!


#ifndef A3_HELP_MESSAGE_REQUESTGOALRESPONSE_H
#define A3_HELP_MESSAGE_REQUESTGOALRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace a3_help
{
template <class ContainerAllocator>
struct RequestGoalResponse_
{
  typedef RequestGoalResponse_<ContainerAllocator> Type;

  RequestGoalResponse_()
    : ack(false)  {
    }
  RequestGoalResponse_(const ContainerAllocator& _alloc)
    : ack(false)  {
    }



   typedef uint8_t _ack_type;
  _ack_type ack;




  typedef boost::shared_ptr< ::a3_help::RequestGoalResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::a3_help::RequestGoalResponse_<ContainerAllocator> const> ConstPtr;

}; // struct RequestGoalResponse_

typedef ::a3_help::RequestGoalResponse_<std::allocator<void> > RequestGoalResponse;

typedef boost::shared_ptr< ::a3_help::RequestGoalResponse > RequestGoalResponsePtr;
typedef boost::shared_ptr< ::a3_help::RequestGoalResponse const> RequestGoalResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::a3_help::RequestGoalResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::a3_help::RequestGoalResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace a3_help

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::a3_help::RequestGoalResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::a3_help::RequestGoalResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::a3_help::RequestGoalResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::a3_help::RequestGoalResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::a3_help::RequestGoalResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::a3_help::RequestGoalResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::a3_help::RequestGoalResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8f5729177853f34b146e2e57766d4dc2";
  }

  static const char* value(const ::a3_help::RequestGoalResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8f5729177853f34bULL;
  static const uint64_t static_value2 = 0x146e2e57766d4dc2ULL;
};

template<class ContainerAllocator>
struct DataType< ::a3_help::RequestGoalResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a3_help/RequestGoalResponse";
  }

  static const char* value(const ::a3_help::RequestGoalResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::a3_help::RequestGoalResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool ack\n\
\n\
";
  }

  static const char* value(const ::a3_help::RequestGoalResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::a3_help::RequestGoalResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ack);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct RequestGoalResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::a3_help::RequestGoalResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::a3_help::RequestGoalResponse_<ContainerAllocator>& v)
  {
    s << indent << "ack: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.ack);
  }
};

} // namespace message_operations
} // namespace ros

#endif // A3_HELP_MESSAGE_REQUESTGOALRESPONSE_H
