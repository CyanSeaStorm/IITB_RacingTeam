// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from shm:srv/ApplyForce.idl
// generated code does not contain a copyright notice

#ifndef SHM__SRV__DETAIL__APPLY_FORCE__STRUCT_H_
#define SHM__SRV__DETAIL__APPLY_FORCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ApplyForce in the package shm.
typedef struct shm__srv__ApplyForce_Request
{
  double force;
} shm__srv__ApplyForce_Request;

// Struct for a sequence of shm__srv__ApplyForce_Request.
typedef struct shm__srv__ApplyForce_Request__Sequence
{
  shm__srv__ApplyForce_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shm__srv__ApplyForce_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ApplyForce in the package shm.
typedef struct shm__srv__ApplyForce_Response
{
  bool success;
  rosidl_runtime_c__String message;
} shm__srv__ApplyForce_Response;

// Struct for a sequence of shm__srv__ApplyForce_Response.
typedef struct shm__srv__ApplyForce_Response__Sequence
{
  shm__srv__ApplyForce_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shm__srv__ApplyForce_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SHM__SRV__DETAIL__APPLY_FORCE__STRUCT_H_
