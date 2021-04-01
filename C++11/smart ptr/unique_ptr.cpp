#include <iostream>

#include "shape.h"

using namespace std;

template <typename T>
class unique_ptr {
 public:
  explicit unique_ptr(T* ptr = nullptr) noexcept : ptr_(ptr) {}
  unique_ptr(unique_ptr& ptr) noexcept = default;
  ~unique_ptr() noexcept { delete ptr_; }

  T& operator*() const noexcept { return *ptr_; }
  T* operator->() const noexcept { return ptr_; }
  T* get() const noexcept { return ptr_; }

  operator bool() const noexcept { return ptr_; }

  unique_ptr(unique_ptr&& other) noexcept { ptr_ = other.release(); }
  template <typename U>
  unique_ptr(unique_ptr<U>&& other) noexcept {
    ptr_ = other.release();
  }

  //! copy and swap 始终只有一个对象管理这块空间的权限
  unique_ptr& operator=(unique_ptr rhs) noexcept {
    rhs.swap(*this);
    return *this;
  }

  /**
   * @brief 原来的指针释放所有权
   * @return 新的具有所有权的指针
   */
  T* release() noexcept {
    T* ptr = ptr_;
    ptr_ = nullptr;
    return ptr;
  }

  void swap(unique_ptr& rhs) noexcept {
    using std::swap;
    //! 转移指针所有权
    swap(ptr_, rhs.ptr_);
  }

 private:
  T* ptr_;
};

int main() {
  unique_ptr<shape> ptr1{create_shape(shape_type::circle)};
  unique_ptr<shape> ptr2{
      ptr1};  // 由于带模板的移动构造函数引发编译器会默认生成拷贝构造

  if (ptr1.get() != nullptr)  // bitwise copy 此时ptr1不为NULL
    ptr2.get()->print();

  unique_ptr<shape> ptr2_2{std::move(
      ptr1)};  // 调用的是默认的移动构造,而不是带模板的移动构造 bitwise move

  if (ptr2_2.get() != nullptr && ptr1.get() != nullptr)  // ptr1 不为空
    ptr2_2.get()->print();

  unique_ptr<shape> ptr3{create_shape(shape_type::rectangle)};
  ptr1 = ptr3;  // ok  根据形参先调用默认拷贝,再调用拷贝赋值
  ptr3 = std::move(ptr1);  // ok
  // 根据形参先调用默认移动构造，而不是带参数的移动构造,再调用移动赋值
  unique_ptr<shape> ptr4(std::move(new circle));  // ok 调用带模板的移动构造

  return 0;
}