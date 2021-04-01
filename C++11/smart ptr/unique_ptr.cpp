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

  //! copy and swap ʼ��ֻ��һ������������ռ��Ȩ��
  unique_ptr& operator=(unique_ptr rhs) noexcept {
    rhs.swap(*this);
    return *this;
  }

  /**
   * @brief ԭ����ָ���ͷ�����Ȩ
   * @return �µľ�������Ȩ��ָ��
   */
  T* release() noexcept {
    T* ptr = ptr_;
    ptr_ = nullptr;
    return ptr;
  }

  void swap(unique_ptr& rhs) noexcept {
    using std::swap;
    //! ת��ָ������Ȩ
    swap(ptr_, rhs.ptr_);
  }

 private:
  T* ptr_;
};

int main() {
  unique_ptr<shape> ptr1{create_shape(shape_type::circle)};
  unique_ptr<shape> ptr2{
      ptr1};  // ���ڴ�ģ����ƶ����캯��������������Ĭ�����ɿ�������

  if (ptr1.get() != nullptr)  // bitwise copy ��ʱptr1��ΪNULL
    ptr2.get()->print();

  unique_ptr<shape> ptr2_2{std::move(
      ptr1)};  // ���õ���Ĭ�ϵ��ƶ�����,�����Ǵ�ģ����ƶ����� bitwise move

  if (ptr2_2.get() != nullptr && ptr1.get() != nullptr)  // ptr1 ��Ϊ��
    ptr2_2.get()->print();

  unique_ptr<shape> ptr3{create_shape(shape_type::rectangle)};
  ptr1 = ptr3;  // ok  �����β��ȵ���Ĭ�Ͽ���,�ٵ��ÿ�����ֵ
  ptr3 = std::move(ptr1);  // ok
  // �����β��ȵ���Ĭ���ƶ����죬�����Ǵ��������ƶ�����,�ٵ����ƶ���ֵ
  unique_ptr<shape> ptr4(std::move(new circle));  // ok ���ô�ģ����ƶ�����

  return 0;
}