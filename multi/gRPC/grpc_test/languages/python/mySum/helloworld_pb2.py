# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: helloworld.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='helloworld.proto',
  package='rpc_package',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=b'\n\x10helloworld.proto\x12\x0brpc_package\"0\n\x0b\x44\x61taRequest\x12\t\n\x01\x61\x18\x01 \x01(\x05\x12\t\n\x01\x62\x18\x02 \x01(\x05\x12\x0b\n\x03msg\x18\x03 \x01(\t\"\x16\n\tDataReply\x12\t\n\x01\x63\x18\x01 \x01(\x05\x32I\n\nAddService\x12;\n\x05myAdd\x12\x18.rpc_package.DataRequest\x1a\x16.rpc_package.DataReply\"\x00\x62\x06proto3'
)




_DATAREQUEST = _descriptor.Descriptor(
  name='DataRequest',
  full_name='rpc_package.DataRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='a', full_name='rpc_package.DataRequest.a', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='b', full_name='rpc_package.DataRequest.b', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='msg', full_name='rpc_package.DataRequest.msg', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=33,
  serialized_end=81,
)


_DATAREPLY = _descriptor.Descriptor(
  name='DataReply',
  full_name='rpc_package.DataReply',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='c', full_name='rpc_package.DataReply.c', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=83,
  serialized_end=105,
)

DESCRIPTOR.message_types_by_name['DataRequest'] = _DATAREQUEST
DESCRIPTOR.message_types_by_name['DataReply'] = _DATAREPLY
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

DataRequest = _reflection.GeneratedProtocolMessageType('DataRequest', (_message.Message,), {
  'DESCRIPTOR' : _DATAREQUEST,
  '__module__' : 'helloworld_pb2'
  # @@protoc_insertion_point(class_scope:rpc_package.DataRequest)
  })
_sym_db.RegisterMessage(DataRequest)

DataReply = _reflection.GeneratedProtocolMessageType('DataReply', (_message.Message,), {
  'DESCRIPTOR' : _DATAREPLY,
  '__module__' : 'helloworld_pb2'
  # @@protoc_insertion_point(class_scope:rpc_package.DataReply)
  })
_sym_db.RegisterMessage(DataReply)



_ADDSERVICE = _descriptor.ServiceDescriptor(
  name='AddService',
  full_name='rpc_package.AddService',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  serialized_start=107,
  serialized_end=180,
  methods=[
  _descriptor.MethodDescriptor(
    name='myAdd',
    full_name='rpc_package.AddService.myAdd',
    index=0,
    containing_service=None,
    input_type=_DATAREQUEST,
    output_type=_DATAREPLY,
    serialized_options=None,
  ),
])
_sym_db.RegisterServiceDescriptor(_ADDSERVICE)

DESCRIPTOR.services_by_name['AddService'] = _ADDSERVICE

# @@protoc_insertion_point(module_scope)