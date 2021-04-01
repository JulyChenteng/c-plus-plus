#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class auto_ptr {
 public:
  explicit auto_ptr(T* ptr = nullptr) noexcept : ptr_(ptr) {}
  ~auto_ptr() noexcept { delete ptr_; }

  T& operator*() const noexcept { return *ptr_; }
  T* operator->() const noexcept { return ptr_; }

  operator bool() const noexcept { return ptr_; }

  T* get() const noexcept { return ptr_; }

  auto_ptr(auto_ptr& other) noexcept { ptr_ = other.release(); }

  //! copy and swap
  auto_ptr& operator=(auto_ptr& rhs) noexcept {
    // auto_prt tmp(rhs.release());
    // tmp.swap(*this);

    //! 上述两行等价于下面一行
    auto_ptr(rhs.release()).swap(*this);
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

  void swap(auto_ptr& rhs) noexcept {
    using std::swap;
    //! 转移指针所有权
    swap(ptr_, rhs.ptr_);
  }

 private:
  T* ptr_;
};

template <typename T>
void swap(auto_ptr<T>& lhs, auto_ptr<T>& rhs) noexcept {
  lhs.swp(rhs);
}

int main() {
  vector<auto_ptr<int>> u(10);
  // u.push_back(new int(5));

  auto_ptr<int> p(new int(5));
  u.push_back(p);
  //u[0] = p;
  
  //cout << *p.get() << endl;
  // auto_ptr<int>& t = p;
  return 0;
}