#include <iostream>

/**
 * @brief scoped_ptr实现 
 * 防止拷贝，避免出现管理权的转移
 * @tparam T 
*/
template <typename T>
class scoped_ptr  // noncopyable
{
 public:
  explicit scoped_ptr(T* ptr = nullptr) noexcept : ptr_(ptr) {}
  ~scoped_ptr() noexcept { delete ptr_; }

  void reset(T* p = nullptr) noexcept { scoped_ptr(p).swap(*this); }

  T& operator*() const noexcept { return *ptr_; }
  T* operator->() const noexcept { return ptr_; }
  T* get() const noexcept { return ptr_; }

  void swap(scoped_ptr& rhs) noexcept {
    using std::swap;
    swap(ptr_, rhs.ptr_);
  }

 private:
  scoped_ptr(scoped_ptr const&) = delete;
  scoped_ptr& operator=(scoped_ptr const&) = delete;

 private:
  T* ptr_;
};

template <typename T>
void swap(scoped_ptr<T>& lhs, scoped_ptr<T>& rhs) noexcept {
  lhs.swap(rhs);
}

int main() { return 0; }