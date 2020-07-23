# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from lama_msgs/GetCrossingRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class GetCrossingRequest(genpy.Message):
  _md5sum = "c5e4a7d59c68f74eabcec876a00216aa"
  _type = "lama_msgs/GetCrossingRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int32 id

"""
  __slots__ = ['id']
  _slot_types = ['int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       id

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(GetCrossingRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.id is None:
        self.id = 0
    else:
      self.id = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      buff.write(_struct_i.pack(self.id))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 4
      (self.id,) = _struct_i.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      buff.write(_struct_i.pack(self.id))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 4
      (self.id,) = _struct_i.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_i = struct.Struct("<i")
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from lama_msgs/GetCrossingResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import lama_msgs.msg
import geometry_msgs.msg

class GetCrossingResponse(genpy.Message):
  _md5sum = "753047a0f3e0e7bbdd77b36b85512c99"
  _type = "lama_msgs/GetCrossingResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """Crossing descriptor


================================================================================
MSG: lama_msgs/Crossing
# The main aim of a crossing is to store frontier information.

# Crossing center.
geometry_msgs/Point center

# Crossing radius.
float32 radius

# Max. range of the data used to compute the crossing.
float32 max_range

Frontier[] frontiers

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: lama_msgs/Frontier
# Frontier is a line segment through which a robot can go.

# First point
geometry_msgs/Point p1

# Second point, so that angle(r-p1, r-p2) is positive, where r is crossing center.
geometry_msgs/Point p2

# Segment length, i.e. width of free space
float32 width

# Angle between x-axis and line between origin and frontier middle. Where x-axis
# and origin refer to the data from which the frontier is computed, in general a LaserScan.
float32 angle

"""
  __slots__ = ['descriptor']
  _slot_types = ['lama_msgs/Crossing']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       descriptor

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(GetCrossingResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.descriptor is None:
        self.descriptor = lama_msgs.msg.Crossing()
    else:
      self.descriptor = lama_msgs.msg.Crossing()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_3d2f.pack(_x.descriptor.center.x, _x.descriptor.center.y, _x.descriptor.center.z, _x.descriptor.radius, _x.descriptor.max_range))
      length = len(self.descriptor.frontiers)
      buff.write(_struct_I.pack(length))
      for val1 in self.descriptor.frontiers:
        _v1 = val1.p1
        _x = _v1
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
        _v2 = val1.p2
        _x = _v2
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
        _x = val1
        buff.write(_struct_2f.pack(_x.width, _x.angle))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.descriptor is None:
        self.descriptor = lama_msgs.msg.Crossing()
      end = 0
      _x = self
      start = end
      end += 32
      (_x.descriptor.center.x, _x.descriptor.center.y, _x.descriptor.center.z, _x.descriptor.radius, _x.descriptor.max_range,) = _struct_3d2f.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.descriptor.frontiers = []
      for i in range(0, length):
        val1 = lama_msgs.msg.Frontier()
        _v3 = val1.p1
        _x = _v3
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        _v4 = val1.p2
        _x = _v4
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        _x = val1
        start = end
        end += 8
        (_x.width, _x.angle,) = _struct_2f.unpack(str[start:end])
        self.descriptor.frontiers.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_3d2f.pack(_x.descriptor.center.x, _x.descriptor.center.y, _x.descriptor.center.z, _x.descriptor.radius, _x.descriptor.max_range))
      length = len(self.descriptor.frontiers)
      buff.write(_struct_I.pack(length))
      for val1 in self.descriptor.frontiers:
        _v5 = val1.p1
        _x = _v5
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
        _v6 = val1.p2
        _x = _v6
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
        _x = val1
        buff.write(_struct_2f.pack(_x.width, _x.angle))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.descriptor is None:
        self.descriptor = lama_msgs.msg.Crossing()
      end = 0
      _x = self
      start = end
      end += 32
      (_x.descriptor.center.x, _x.descriptor.center.y, _x.descriptor.center.z, _x.descriptor.radius, _x.descriptor.max_range,) = _struct_3d2f.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.descriptor.frontiers = []
      for i in range(0, length):
        val1 = lama_msgs.msg.Frontier()
        _v7 = val1.p1
        _x = _v7
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        _v8 = val1.p2
        _x = _v8
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        _x = val1
        start = end
        end += 8
        (_x.width, _x.angle,) = _struct_2f.unpack(str[start:end])
        self.descriptor.frontiers.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_2f = struct.Struct("<2f")
_struct_3d2f = struct.Struct("<3d2f")
_struct_3d = struct.Struct("<3d")
class GetCrossing(object):
  _type          = 'lama_msgs/GetCrossing'
  _md5sum = '4842af2f1edf5a2e9caf0cee19515bcc'
  _request_class  = GetCrossingRequest
  _response_class = GetCrossingResponse
