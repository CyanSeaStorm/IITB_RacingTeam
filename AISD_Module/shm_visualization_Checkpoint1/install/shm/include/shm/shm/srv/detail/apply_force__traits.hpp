// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from shm:srv/ApplyForce.idl
// generated code does not contain a copyright notice

#ifndef SHM__SRV__DETAIL__APPLY_FORCE__TRAITS_HPP_
#define SHM__SRV__DETAIL__APPLY_FORCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "shm/srv/detail/apply_force__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace shm
{

namespace srv
{

inline void to_flow_style_yaml(
  const ApplyForce_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: force
  {
    out << "force: ";
    rosidl_generator_traits::value_to_yaml(msg.force, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ApplyForce_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: force
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force: ";
    rosidl_generator_traits::value_to_yaml(msg.force, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ApplyForce_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace shm

namespace rosidl_generator_traits
{

[[deprecated("use shm::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const shm::srv::ApplyForce_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  shm::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use shm::srv::to_yaml() instead")]]
inline std::string to_yaml(const shm::srv::ApplyForce_Request & msg)
{
  return shm::srv::to_yaml(msg);
}

template<>
inline const char * data_type<shm::srv::ApplyForce_Request>()
{
  return "shm::srv::ApplyForce_Request";
}

template<>
inline const char * name<shm::srv::ApplyForce_Request>()
{
  return "shm/srv/ApplyForce_Request";
}

template<>
struct has_fixed_size<shm::srv::ApplyForce_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<shm::srv::ApplyForce_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<shm::srv::ApplyForce_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace shm
{

namespace srv
{

inline void to_flow_style_yaml(
  const ApplyForce_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ApplyForce_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ApplyForce_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace shm

namespace rosidl_generator_traits
{

[[deprecated("use shm::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const shm::srv::ApplyForce_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  shm::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use shm::srv::to_yaml() instead")]]
inline std::string to_yaml(const shm::srv::ApplyForce_Response & msg)
{
  return shm::srv::to_yaml(msg);
}

template<>
inline const char * data_type<shm::srv::ApplyForce_Response>()
{
  return "shm::srv::ApplyForce_Response";
}

template<>
inline const char * name<shm::srv::ApplyForce_Response>()
{
  return "shm/srv/ApplyForce_Response";
}

template<>
struct has_fixed_size<shm::srv::ApplyForce_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<shm::srv::ApplyForce_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<shm::srv::ApplyForce_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<shm::srv::ApplyForce>()
{
  return "shm::srv::ApplyForce";
}

template<>
inline const char * name<shm::srv::ApplyForce>()
{
  return "shm/srv/ApplyForce";
}

template<>
struct has_fixed_size<shm::srv::ApplyForce>
  : std::integral_constant<
    bool,
    has_fixed_size<shm::srv::ApplyForce_Request>::value &&
    has_fixed_size<shm::srv::ApplyForce_Response>::value
  >
{
};

template<>
struct has_bounded_size<shm::srv::ApplyForce>
  : std::integral_constant<
    bool,
    has_bounded_size<shm::srv::ApplyForce_Request>::value &&
    has_bounded_size<shm::srv::ApplyForce_Response>::value
  >
{
};

template<>
struct is_service<shm::srv::ApplyForce>
  : std::true_type
{
};

template<>
struct is_service_request<shm::srv::ApplyForce_Request>
  : std::true_type
{
};

template<>
struct is_service_response<shm::srv::ApplyForce_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SHM__SRV__DETAIL__APPLY_FORCE__TRAITS_HPP_
