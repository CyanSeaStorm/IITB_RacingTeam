// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from shm:srv/SetSHMParams.idl
// generated code does not contain a copyright notice

#ifndef SHM__SRV__DETAIL__SET_SHM_PARAMS__STRUCT_H_
#define SHM__SRV__DETAIL__SET_SHM_PARAMS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetSHMParams in the package shm.
typedef struct shm__srv__SetSHMParams_Request
{
  double mass;
  double omega;
  double beta;
} shm__srv__SetSHMParams_Request;

// Struct for a sequence of shm__srv__SetSHMParams_Request.
typedef struct shm__srv__SetSHMParams_Request__Sequence
{
  shm__srv__SetSHMParams_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shm__srv__SetSHMParams_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetSHMParams in the package shm.
typedef struct shm__srv__SetSHMParams_Response
{
  bool success;
  rosidl_runtime_c__String message;
} shm__srv__SetSHMParams_Response;

// Struct for a sequence of shm__srv__SetSHMParams_Response.
typedef struct shm__srv__SetSHMParams_Response__Sequence
{
  shm__srv__SetSHMParams_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shm__srv__SetSHMParams_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SHM__SRV__DETAIL__SET_SHM_PARAMS__STRUCT_H_
