// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from shm:srv/ApplyForce.idl
// generated code does not contain a copyright notice

#ifndef SHM__SRV__DETAIL__APPLY_FORCE__BUILDER_HPP_
#define SHM__SRV__DETAIL__APPLY_FORCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "shm/srv/detail/apply_force__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace shm
{

namespace srv
{

namespace builder
{

class Init_ApplyForce_Request_force
{
public:
  Init_ApplyForce_Request_force()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::shm::srv::ApplyForce_Request force(::shm::srv::ApplyForce_Request::_force_type arg)
  {
    msg_.force = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shm::srv::ApplyForce_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::shm::srv::ApplyForce_Request>()
{
  return shm::srv::builder::Init_ApplyForce_Request_force();
}

}  // namespace shm


namespace shm
{

namespace srv
{

namespace builder
{

class Init_ApplyForce_Response_message
{
public:
  explicit Init_ApplyForce_Response_message(::shm::srv::ApplyForce_Response & msg)
  : msg_(msg)
  {}
  ::shm::srv::ApplyForce_Response message(::shm::srv::ApplyForce_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shm::srv::ApplyForce_Response msg_;
};

class Init_ApplyForce_Response_success
{
public:
  Init_ApplyForce_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ApplyForce_Response_message success(::shm::srv::ApplyForce_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ApplyForce_Response_message(msg_);
  }

private:
  ::shm::srv::ApplyForce_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::shm::srv::ApplyForce_Response>()
{
  return shm::srv::builder::Init_ApplyForce_Response_success();
}

}  // namespace shm

#endif  // SHM__SRV__DETAIL__APPLY_FORCE__BUILDER_HPP_
