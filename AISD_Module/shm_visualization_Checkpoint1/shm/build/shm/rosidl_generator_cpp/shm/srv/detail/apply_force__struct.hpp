// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from shm:srv/ApplyForce.idl
// generated code does not contain a copyright notice

#ifndef SHM__SRV__DETAIL__APPLY_FORCE__STRUCT_HPP_
#define SHM__SRV__DETAIL__APPLY_FORCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__shm__srv__ApplyForce_Request __attribute__((deprecated))
#else
# define DEPRECATED__shm__srv__ApplyForce_Request __declspec(deprecated)
#endif

namespace shm
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ApplyForce_Request_
{
  using Type = ApplyForce_Request_<ContainerAllocator>;

  explicit ApplyForce_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->force = 0.0;
    }
  }

  explicit ApplyForce_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->force = 0.0;
    }
  }

  // field types and members
  using _force_type =
    double;
  _force_type force;

  // setters for named parameter idiom
  Type & set__force(
    const double & _arg)
  {
    this->force = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    shm::srv::ApplyForce_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const shm::srv::ApplyForce_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<shm::srv::ApplyForce_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<shm::srv::ApplyForce_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      shm::srv::ApplyForce_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<shm::srv::ApplyForce_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      shm::srv::ApplyForce_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<shm::srv::ApplyForce_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<shm::srv::ApplyForce_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<shm::srv::ApplyForce_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__shm__srv__ApplyForce_Request
    std::shared_ptr<shm::srv::ApplyForce_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__shm__srv__ApplyForce_Request
    std::shared_ptr<shm::srv::ApplyForce_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ApplyForce_Request_ & other) const
  {
    if (this->force != other.force) {
      return false;
    }
    return true;
  }
  bool operator!=(const ApplyForce_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ApplyForce_Request_

// alias to use template instance with default allocator
using ApplyForce_Request =
  shm::srv::ApplyForce_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace shm


#ifndef _WIN32
# define DEPRECATED__shm__srv__ApplyForce_Response __attribute__((deprecated))
#else
# define DEPRECATED__shm__srv__ApplyForce_Response __declspec(deprecated)
#endif

namespace shm
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ApplyForce_Response_
{
  using Type = ApplyForce_Response_<ContainerAllocator>;

  explicit ApplyForce_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit ApplyForce_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    shm::srv::ApplyForce_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const shm::srv::ApplyForce_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<shm::srv::ApplyForce_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<shm::srv::ApplyForce_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      shm::srv::ApplyForce_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<shm::srv::ApplyForce_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      shm::srv::ApplyForce_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<shm::srv::ApplyForce_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<shm::srv::ApplyForce_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<shm::srv::ApplyForce_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__shm__srv__ApplyForce_Response
    std::shared_ptr<shm::srv::ApplyForce_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__shm__srv__ApplyForce_Response
    std::shared_ptr<shm::srv::ApplyForce_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ApplyForce_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const ApplyForce_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ApplyForce_Response_

// alias to use template instance with default allocator
using ApplyForce_Response =
  shm::srv::ApplyForce_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace shm

namespace shm
{

namespace srv
{

struct ApplyForce
{
  using Request = shm::srv::ApplyForce_Request;
  using Response = shm::srv::ApplyForce_Response;
};

}  // namespace srv

}  // namespace shm

#endif  // SHM__SRV__DETAIL__APPLY_FORCE__STRUCT_HPP_
