// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from shm:srv/SetSHMParams.idl
// generated code does not contain a copyright notice

#ifndef SHM__SRV__DETAIL__SET_SHM_PARAMS__BUILDER_HPP_
#define SHM__SRV__DETAIL__SET_SHM_PARAMS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "shm/srv/detail/set_shm_params__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace shm
{

namespace srv
{

namespace builder
{

class Init_SetSHMParams_Request_beta
{
public:
  explicit Init_SetSHMParams_Request_beta(::shm::srv::SetSHMParams_Request & msg)
  : msg_(msg)
  {}
  ::shm::srv::SetSHMParams_Request beta(::shm::srv::SetSHMParams_Request::_beta_type arg)
  {
    msg_.beta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shm::srv::SetSHMParams_Request msg_;
};

class Init_SetSHMParams_Request_omega
{
public:
  explicit Init_SetSHMParams_Request_omega(::shm::srv::SetSHMParams_Request & msg)
  : msg_(msg)
  {}
  Init_SetSHMParams_Request_beta omega(::shm::srv::SetSHMParams_Request::_omega_type arg)
  {
    msg_.omega = std::move(arg);
    return Init_SetSHMParams_Request_beta(msg_);
  }

private:
  ::shm::srv::SetSHMParams_Request msg_;
};

class Init_SetSHMParams_Request_mass
{
public:
  Init_SetSHMParams_Request_mass()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetSHMParams_Request_omega mass(::shm::srv::SetSHMParams_Request::_mass_type arg)
  {
    msg_.mass = std::move(arg);
    return Init_SetSHMParams_Request_omega(msg_);
  }

private:
  ::shm::srv::SetSHMParams_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::shm::srv::SetSHMParams_Request>()
{
  return shm::srv::builder::Init_SetSHMParams_Request_mass();
}

}  // namespace shm


namespace shm
{

namespace srv
{

namespace builder
{

class Init_SetSHMParams_Response_message
{
public:
  explicit Init_SetSHMParams_Response_message(::shm::srv::SetSHMParams_Response & msg)
  : msg_(msg)
  {}
  ::shm::srv::SetSHMParams_Response message(::shm::srv::SetSHMParams_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shm::srv::SetSHMParams_Response msg_;
};

class Init_SetSHMParams_Response_success
{
public:
  Init_SetSHMParams_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetSHMParams_Response_message success(::shm::srv::SetSHMParams_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetSHMParams_Response_message(msg_);
  }

private:
  ::shm::srv::SetSHMParams_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::shm::srv::SetSHMParams_Response>()
{
  return shm::srv::builder::Init_SetSHMParams_Response_success();
}

}  // namespace shm

#endif  // SHM__SRV__DETAIL__SET_SHM_PARAMS__BUILDER_HPP_
