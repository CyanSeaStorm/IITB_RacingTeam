// generated from rosidl_generator_cpp/resource/rosidl_generator_cpp__visibility_control.hpp.in
// generated code does not contain a copyright notice

#ifndef SHM__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
#define SHM__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_CPP_EXPORT_shm __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_CPP_IMPORT_shm __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_CPP_EXPORT_shm __declspec(dllexport)
    #define ROSIDL_GENERATOR_CPP_IMPORT_shm __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_CPP_BUILDING_DLL_shm
    #define ROSIDL_GENERATOR_CPP_PUBLIC_shm ROSIDL_GENERATOR_CPP_EXPORT_shm
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_shm ROSIDL_GENERATOR_CPP_IMPORT_shm
  #endif
#else
  #define ROSIDL_GENERATOR_CPP_EXPORT_shm __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_CPP_IMPORT_shm
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_CPP_PUBLIC_shm __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_shm
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // SHM__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
