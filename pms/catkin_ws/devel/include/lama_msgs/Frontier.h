// Generated by gencpp from file lama_msgs/Frontier.msg
// DO NOT EDIT!


#ifndef LAMA_MSGS_MESSAGE_FRONTIER_H
#define LAMA_MSGS_MESSAGE_FRONTIER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Point.h>
#include <geometry_msgs/Point.h>

namespace lama_msgs
{
template <class ContainerAllocator>
struct Frontier_
{
  typedef Frontier_<ContainerAllocator> Type;

  Frontier_()
    : p1()
    , p2()
    , width(0.0)
    , angle(0.0)  {
    }
  Frontier_(const ContainerAllocator& _alloc)
    : p1(_alloc)
    , p2(_alloc)
    , width(0.0)
    , angle(0.0)  {
    }



   typedef  ::geometry_msgs::Point_<ContainerAllocator>  _p1_type;
  _p1_type p1;

   typedef  ::geometry_msgs::Point_<ContainerAllocator>  _p2_type;
  _p2_type p2;

   typedef float _width_type;
  _width_type width;

   typedef float _angle_type;
  _angle_type angle;




  typedef boost::shared_ptr< ::lama_msgs::Frontier_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::lama_msgs::Frontier_<ContainerAllocator> const> ConstPtr;

}; // struct Frontier_

typedef ::lama_msgs::Frontier_<std::allocator<void> > Frontier;

typedef boost::shared_ptr< ::lama_msgs::Frontier > FrontierPtr;
typedef boost::shared_ptr< ::lama_msgs::Frontier const> FrontierConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::lama_msgs::Frontier_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::lama_msgs::Frontier_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace lama_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'lama_msgs': ['/lu1/smagri/uni/subj/proj30cp/catkin_ws/src/lama_msgs/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::lama_msgs::Frontier_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::lama_msgs::Frontier_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lama_msgs::Frontier_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lama_msgs::Frontier_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lama_msgs::Frontier_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lama_msgs::Frontier_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::lama_msgs::Frontier_<ContainerAllocator> >
{
  static const char* value()
  {
    return "626f51fb9d901b07427079891bd87ce3";
  }

  static const char* value(const ::lama_msgs::Frontier_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x626f51fb9d901b07ULL;
  static const uint64_t static_value2 = 0x427079891bd87ce3ULL;
};

template<class ContainerAllocator>
struct DataType< ::lama_msgs::Frontier_<ContainerAllocator> >
{
  static const char* value()
  {
    return "lama_msgs/Frontier";
  }

  static const char* value(const ::lama_msgs::Frontier_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::lama_msgs::Frontier_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Frontier is a line segment through which a robot can go.\n\
\n\
# First point\n\
geometry_msgs/Point p1\n\
\n\
# Second point, so that angle(r-p1, r-p2) is positive, where r is crossing center.\n\
geometry_msgs/Point p2\n\
\n\
# Segment length, i.e. width of free space\n\
float32 width\n\
\n\
# Angle between x-axis and line between origin and frontier middle. Where x-axis\n\
# and origin refer to the data from which the frontier is computed, in general a LaserScan.\n\
float32 angle\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::lama_msgs::Frontier_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::lama_msgs::Frontier_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.p1);
      stream.next(m.p2);
      stream.next(m.width);
      stream.next(m.angle);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Frontier_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::lama_msgs::Frontier_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::lama_msgs::Frontier_<ContainerAllocator>& v)
  {
    s << indent << "p1: ";
    s << std::endl;
    Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "  ", v.p1);
    s << indent << "p2: ";
    s << std::endl;
    Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "  ", v.p2);
    s << indent << "width: ";
    Printer<float>::stream(s, indent + "  ", v.width);
    s << indent << "angle: ";
    Printer<float>::stream(s, indent + "  ", v.angle);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LAMA_MSGS_MESSAGE_FRONTIER_H
