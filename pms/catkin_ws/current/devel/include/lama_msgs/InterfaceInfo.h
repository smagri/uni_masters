// Generated by gencpp from file lama_msgs/InterfaceInfo.msg
// DO NOT EDIT!


#ifndef LAMA_MSGS_MESSAGE_INTERFACEINFO_H
#define LAMA_MSGS_MESSAGE_INTERFACEINFO_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace lama_msgs
{
template <class ContainerAllocator>
struct InterfaceInfo_
{
  typedef InterfaceInfo_<ContainerAllocator> Type;

  InterfaceInfo_()
    : interface_name()
    , message_type()
    , get_service_name()
    , get_service_type()
    , set_service_name()
    , set_service_type()
    , interface_type()
    , timestamp()  {
    }
  InterfaceInfo_(const ContainerAllocator& _alloc)
    : interface_name(_alloc)
    , message_type(_alloc)
    , get_service_name(_alloc)
    , get_service_type(_alloc)
    , set_service_name(_alloc)
    , set_service_type(_alloc)
    , interface_type(_alloc)
    , timestamp()  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _interface_name_type;
  _interface_name_type interface_name;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _message_type_type;
  _message_type_type message_type;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _get_service_name_type;
  _get_service_name_type get_service_name;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _get_service_type_type;
  _get_service_type_type get_service_type;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _set_service_name_type;
  _set_service_name_type set_service_name;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _set_service_type_type;
  _set_service_type_type set_service_type;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _interface_type_type;
  _interface_type_type interface_type;

   typedef ros::Time _timestamp_type;
  _timestamp_type timestamp;




  typedef boost::shared_ptr< ::lama_msgs::InterfaceInfo_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::lama_msgs::InterfaceInfo_<ContainerAllocator> const> ConstPtr;

}; // struct InterfaceInfo_

typedef ::lama_msgs::InterfaceInfo_<std::allocator<void> > InterfaceInfo;

typedef boost::shared_ptr< ::lama_msgs::InterfaceInfo > InterfaceInfoPtr;
typedef boost::shared_ptr< ::lama_msgs::InterfaceInfo const> InterfaceInfoConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::lama_msgs::InterfaceInfo_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::lama_msgs::InterfaceInfo_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace lama_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'lama_msgs': ['/lu1/smagri/uni/subj/proj30cp/catkin_ws/src/lama_msgs/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::lama_msgs::InterfaceInfo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::lama_msgs::InterfaceInfo_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lama_msgs::InterfaceInfo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lama_msgs::InterfaceInfo_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lama_msgs::InterfaceInfo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lama_msgs::InterfaceInfo_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::lama_msgs::InterfaceInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "156de5bd66b7a123b19f5a2142f26e8c";
  }

  static const char* value(const ::lama_msgs::InterfaceInfo_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x156de5bd66b7a123ULL;
  static const uint64_t static_value2 = 0xb19f5a2142f26e8cULL;
};

template<class ContainerAllocator>
struct DataType< ::lama_msgs::InterfaceInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "lama_msgs/InterfaceInfo";
  }

  static const char* value(const ::lama_msgs::InterfaceInfo_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::lama_msgs::InterfaceInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Interface name.\n\
string interface_name\n\
\n\
# The type of message associated with the interface.\n\
string message_type\n\
\n\
# The name of the associated service for getting a message.\n\
string get_service_name\n\
\n\
# The service message of the service for getting a message.\n\
string get_service_type\n\
\n\
# The name of the associated service for setting a message.\n\
string set_service_name\n\
\n\
# The service message of the service for setting a message.\n\
string set_service_type\n\
\n\
string interface_type\n\
\n\
# Timestamp of the last added message through this interface.\n\
time timestamp\n\
";
  }

  static const char* value(const ::lama_msgs::InterfaceInfo_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::lama_msgs::InterfaceInfo_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.interface_name);
      stream.next(m.message_type);
      stream.next(m.get_service_name);
      stream.next(m.get_service_type);
      stream.next(m.set_service_name);
      stream.next(m.set_service_type);
      stream.next(m.interface_type);
      stream.next(m.timestamp);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct InterfaceInfo_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::lama_msgs::InterfaceInfo_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::lama_msgs::InterfaceInfo_<ContainerAllocator>& v)
  {
    s << indent << "interface_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.interface_name);
    s << indent << "message_type: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.message_type);
    s << indent << "get_service_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.get_service_name);
    s << indent << "get_service_type: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.get_service_type);
    s << indent << "set_service_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.set_service_name);
    s << indent << "set_service_type: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.set_service_type);
    s << indent << "interface_type: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.interface_type);
    s << indent << "timestamp: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.timestamp);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LAMA_MSGS_MESSAGE_INTERFACEINFO_H
