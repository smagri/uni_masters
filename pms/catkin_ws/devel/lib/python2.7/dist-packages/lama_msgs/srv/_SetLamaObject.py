# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from lama_msgs/SetLamaObjectRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import lama_msgs.msg

class SetLamaObjectRequest(genpy.Message):
  _md5sum = "eea5eb07a771e62f930c7318a67ee584"
  _type = "lama_msgs/SetLamaObjectRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """LamaObject object

================================================================================
MSG: lama_msgs/LamaObject
# id of lama object in the database, will be unique.
# When adding a vertex into the database, this id will be ignored.
int32 id

# id of lama object in the world (usage is implementation specific).
int32 id_in_world

# name of object
string name

# emitter id and name.
int32 emitter_id
string emitter_name

# type: "EDGE" or "VERTEX"
int32 type
int32 VERTEX = 1
int32 EDGE = 2

# for edges: start and end vertices
# for vertices: not used
int32[2] references


"""
  __slots__ = ['object']
  _slot_types = ['lama_msgs/LamaObject']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       object

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SetLamaObjectRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.object is None:
        self.object = lama_msgs.msg.LamaObject()
    else:
      self.object = lama_msgs.msg.LamaObject()

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
      buff.write(_struct_2i.pack(_x.object.id, _x.object.id_in_world))
      _x = self.object.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_i.pack(self.object.emitter_id))
      _x = self.object.emitter_name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_i.pack(self.object.type))
      buff.write(_struct_2i.pack(*self.object.references))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.object is None:
        self.object = lama_msgs.msg.LamaObject()
      end = 0
      _x = self
      start = end
      end += 8
      (_x.object.id, _x.object.id_in_world,) = _struct_2i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.object.name = str[start:end].decode('utf-8')
      else:
        self.object.name = str[start:end]
      start = end
      end += 4
      (self.object.emitter_id,) = _struct_i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.object.emitter_name = str[start:end].decode('utf-8')
      else:
        self.object.emitter_name = str[start:end]
      start = end
      end += 4
      (self.object.type,) = _struct_i.unpack(str[start:end])
      start = end
      end += 8
      self.object.references = _struct_2i.unpack(str[start:end])
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
      buff.write(_struct_2i.pack(_x.object.id, _x.object.id_in_world))
      _x = self.object.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_i.pack(self.object.emitter_id))
      _x = self.object.emitter_name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_i.pack(self.object.type))
      buff.write(self.object.references.tostring())
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.object is None:
        self.object = lama_msgs.msg.LamaObject()
      end = 0
      _x = self
      start = end
      end += 8
      (_x.object.id, _x.object.id_in_world,) = _struct_2i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.object.name = str[start:end].decode('utf-8')
      else:
        self.object.name = str[start:end]
      start = end
      end += 4
      (self.object.emitter_id,) = _struct_i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.object.emitter_name = str[start:end].decode('utf-8')
      else:
        self.object.emitter_name = str[start:end]
      start = end
      end += 4
      (self.object.type,) = _struct_i.unpack(str[start:end])
      start = end
      end += 8
      self.object.references = numpy.frombuffer(str[start:end], dtype=numpy.int32, count=2)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_i = struct.Struct("<i")
_struct_2i = struct.Struct("<2i")
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from lama_msgs/SetLamaObjectResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class SetLamaObjectResponse(genpy.Message):
  _md5sum = "c5e4a7d59c68f74eabcec876a00216aa"
  _type = "lama_msgs/SetLamaObjectResponse"
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
      super(SetLamaObjectResponse, self).__init__(*args, **kwds)
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
class SetLamaObject(object):
  _type          = 'lama_msgs/SetLamaObject'
  _md5sum = 'f191a122fd81f40804a5436e7a94b04c'
  _request_class  = SetLamaObjectRequest
  _response_class = SetLamaObjectResponse
