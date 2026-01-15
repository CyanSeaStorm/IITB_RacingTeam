// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from shm:srv/SetSHMParams.idl
// generated code does not contain a copyright notice

#ifndef SHM__SRV__DETAIL__SET_SHM_PARAMS__TRAITS_HPP_
#define SHM__SRV__DETAIL__SET_SHM_PARAMS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "shm/srv/detail/set_shm_params__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace shm
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetSHMParams_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: mass
  {
    out << "mass: ";
    rosidl_generator_traits::value_to_yaml(msg.mass, out);
    out << ", ";
  }

  // member: omega
  {
    out << "omega: ";
    rosidl_generator_traits::value_to_yaml(msg.omega, out);
    out << ", ";
  }

  // member: beta
  {
    out << "beta: ";
    rosidl_generator_traits::value_to_yaml(msg.beta, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetSHMParams_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mass
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mass: ";
    rosidl_generator_traits::value_to_yaml(msg.mass, out);
    out << "\n";
  }

  // member: omega
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "omega: ";
    rosidl_generator_traits::value_to_yaml(msg.omega, out);
    out << "\n";
  }

  // member: beta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "beta: ";
    rosidl_generator_traits::value_to_yaml(msg.beta, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetSHMParams_Request & msg, bool use_flow_style = false)
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
  const shm::srv::SetSHMParams_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  shm::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use shm::srv::to_yaml() instead")]]
inline std::string to_yaml(const shm::srv::SetSHMParams_Request & msg)
{
  return shm::srv::to_yaml(msg);
}

template<>
inline const char * data_type<shm::srv::SetSHMParams_Request>()
{
  return "shm::srv::SetSHMParams_Request";
}

template<>
inline const char * name<shm::srv::SetSHMParams_Request>()
{
  return "shm/srv/SetSHMParams_Request";
}

template<>
struct has_fixed_size<shm::srv::SetSHMParams_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<shm::srv::SetSHMParams_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<shm::srv::SetSHMParams_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace shm
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetSHMParams_Response & msg,
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
  const SetSHMParams_Response & msg,
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

inline std::string to_yaml(const SetSHMParams_Response & msg, bool use_flow_style = false)
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
  const shm::srv::SetSHMParams_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  shm::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use shm::srv::to_yaml() instead")]]
inline std::string to_yaml(const shm::srv::SetSHMParams_Response & msg)
{
  return shm::srv::to_yaml(msg);
}

template<>
inline const char * data_type<shm::srv::SetSHMParams_Response>()
{
  return "shm::srv::SetSHMParams_Response";
}

template<>
inline const char * name<shm::srv::SetSHMParams_Response>()
{
  return "shm/srv/SetSHMParams_Response";
}

template<>
struct has_fixed_size<shm::srv::SetSHMParams_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<shm::srv::SetSHMParams_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<shm::srv::SetSHMParams_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<shm::srv::SetSHMParams>()
{
  return "shm::srv::SetSHMParams";
}

template<>
inline const char * name<shm::srv::SetSHMParams>()
{
  return "shm/srv/SetSHMParams";
}

template<>
struct has_fixed_size<shm::srv::SetSHMParams>
  : std::integral_constant<
    bool,
    has_fixed_size<shm::srv::SetSHMParams_Request>::value &&
    has_fixed_size<shm::srv::SetSHMParams_Response>::value
  >
{
};

template<>
struct has_bounded_size<shm::srv::SetSHMParams>
  : std::integral_constant<
    bool,
    has_bounded_size<shm::srv::SetSHMParams_Request>::value &&
    has_bounded_size<shm::srv::SetSHMParams_Response>::value
  >
{
};

template<>
struct is_service<shm::srv::SetSHMParams>
  : std::true_type
{
};

template<>
struct is_service_request<shm::srv::SetSHMParams_Request>
  : std::true_type
{
};

template<>
struct is_service_response<shm::srv::SetSHMParams_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SHM__SRV__DETAIL__SET_SHM_PARAMS__TRAITS_HPP_
