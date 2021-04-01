#include "shape.h"

class shared_count {
 public:
  shared_count() : count_(1) {}

  // ���Ӽ���
  void add_count() { ++count_; }

  // ���ټ���
  long reduce_count() { return --count_; }

  // ��ȡ��ǰ����
  long get_count() const { return count_; }

 private:
  long count_;
};

template <typename T>
class shared_ptr {
 public:
  explicit shared_ptr(T *ptr = nullptr) noexcept : ptr_(ptr) {
    if (ptr) {
      shared_count_ = new shared_count();
    }
  }

  // ʵ��ǿ������ת����Ҫ�Ĺ��캯��
  template <typename U>
  shared_ptr(const shared_ptr<U> &other, T *ptr) noexcept {
    ptr_ = ptr;
    if (ptr_) {
      other.shared_count_->add_count();
      shared_count_ = other.shared_count_;
    }
  }

  ~shared_ptr() noexcept {
    // ���һ��shared_ptr��ȥɾ�������빲�����
    // ptr_��Ϊ���Ҵ�ʱ���������Ϊ0��ʱ��,��ȥɾ��
    if (ptr_ && !shared_count_->reduce_count()) {
      delete ptr_;
      delete shared_count_;
    }
  }

  T &operator*() const noexcept { return *ptr_; }

  T *operator->() const noexcept { return ptr_; }

  operator bool() const noexcept { return ptr_; }

  T *get() const noexcept { return ptr_; }

  // ��ģ��Ŀ������ƶ����캯�� ģ��ĸ���ʵ���䲢����Ȼ���� friend
  // ��ϵ��������ܻ���˽�г�Ա ptr_ �� shared_count_�� ��Ҫ������ʾ����
  template <typename U>
  friend class shared_ptr;

  template <typename U>
  shared_ptr(const shared_ptr<U> &other) noexcept {
    //        cout << "�����˴�ģ��Ŀ�������!" << endl;
    ptr_ = other.ptr_;
    if (ptr_) {
      other.shared_count_->add_count();
      shared_count_ = other.shared_count_;
    }
  }

  template <typename U>
  shared_ptr(shared_ptr<U> &&other) noexcept {
    //        cout << "�����˴�ģ����ƶ�����!" << endl;
    ptr_ = other.ptr_;
    if (ptr_) {
      shared_count_ = other.shared_count_;
      other.ptr_ = nullptr;
      other.shared_count_ = nullptr;
    }
  }

  // copy and swap  ʼ��ֻ��һ�������й������ռ��Ȩ��
  shared_ptr &operator=(shared_ptr rhs) noexcept {
    rhs.swap(*this);
    return *this;
  }

  void swap(shared_ptr &rhs) noexcept {
    using std::swap;
    swap(ptr_, rhs.ptr_);
    swap(shared_count_, rhs.shared_count_);
  }

  long use_count() const noexcept {
    if (ptr_) {
      return shared_count_->get_count();
    } else {
      return 0;
    }
  }

 private:
  T *ptr_;
  shared_count *shared_count_;
};

template <typename T>
void swap(shared_ptr<T> &lhs, shared_ptr<T> &rhs) noexcept {
  lhs.swap(rhs);
}

template <typename T, typename U>
shared_ptr<T> dynamic_pointer_cast(const shared_ptr<U> &other) noexcept {
  T *ptr = dynamic_cast<T *>(other.get());
  return shared_ptr<T>(other, ptr);
}

template <typename T, typename U>
shared_ptr<T> static_pointer_cast(const shared_ptr<U> &other) noexcept {
  T *ptr = static_cast<T *>(other.get());
  return shared_ptr<T>(other, ptr);
}

template <typename T, typename U>
shared_ptr<T> const_pointer_cast(const shared_ptr<U> &other) noexcept {
  T *ptr = const_cast<T *>(other.get());
  return shared_ptr<T>(other, ptr);
}

template <typename T, typename U>
shared_ptr<T> reinterpret_pointer_cast(const shared_ptr<U> &other) noexcept {
  T *ptr = reinterpret_cast<T *>(other.get());
  return shared_ptr<T>(other, ptr);
}

int main() {
  shared_ptr<circle> ptr1(new circle());
  cout << "use count of ptr1 is " << ptr1.use_count() << endl;
  shared_ptr<shape> ptr2, ptr3;
  cout << "use count of ptr2 was " << ptr2.use_count() << endl;
  ptr2 =
      ptr1;  // shared_ptr<circle>��ʽת��shared_ptr<shape> ���ô�ģ��Ŀ�������
             //    cout<<"======="<<endl;
  //    ptr3 = ptr2;        // ���õ��Ǳ��������ɵ�Ĭ�Ͽ�������
  //    �������ü����������� ptr3=ptr2 cout<<"======="<<endl;
  ptr3 = ptr1;
  cout << "��ʱ3��shared_ptrָ��ͬһ����Դ" << endl;
  cout << "use count of ptr1 is now " << ptr1.use_count() << endl;
  cout << "use count of ptr2 is now " << ptr2.use_count() << endl;
  cout << "use count of ptr3 is now " << ptr3.use_count() << endl;
  if (ptr1) cout << "ptr1 is not empty" << endl;
  // ���ȵ��ø�ֵ����,�ɱ������������õ��ǿ������컹���ƶ�����,���һ���µ���ʱ�������,��ʱ��������������������������
  // ������������,�����жϸ���ʱ������Ƿ�ָ����Դ,���û��,��������������,�����ü�����1,�ж����ü����Ƿ�Ϊ0,���Ϊ0,ɾ���������ü���ָ��,���򲻲�����
  cout << "��ʱ2��shared_ptrָ��ͬһ����Դ" << endl;
  ptr2 = std::move(ptr1);
  if (!ptr1 && ptr2) {  // ���õ���bool���ز�����
    cout << "ptr1 move to ptr2" << endl;
    cout << "use count of ptr1 is now " << ptr1.use_count() << endl;
    cout << "use count of ptr2 is now " << ptr2.use_count() << endl;
    cout << "use count of ptr3 is now " << ptr3.use_count() << endl;
  }
  // shape* -> circle*
  // ʹ��dynamic_castת����,ָ��Ϊ��.��ʱ��Դ���Ǳ�dptr2ӵ��,dptr1Ϊ0
  shared_ptr<shape> dptr2(new shape);
  shared_ptr<circle> dptr1 = dynamic_pointer_cast<circle>(dptr2);  // ����ת����

  cout << "use count of dptr1 is now " << dptr1.use_count() << endl;  // 0
  cout << "use count of dptr2 is now " << dptr2.use_count() << endl;  // 1

  // circle* -> circle*
  // ʹ��dynamic_castת����,ָ�벻Ϊ��,��ʱ��Դ�����߹�ͬʹ��,���ü���Ϊ2
  shared_ptr<shape> dptr3(new circle);
  //    shared_ptr<circle> dptr3(new circle);     //
  //    ������ߵ�ǰ��,�������һ����
  shared_ptr<circle> dptr1_1 =
      dynamic_pointer_cast<circle>(dptr3);  // ����ת����

  cout << "use count of dptr1_1 is now " << dptr1_1.use_count() << endl;  // 2
  cout << "use count of dptr3 is now " << dptr3.use_count() << endl;      // 2

  // circle* -> circle*
  // ʹ��dynamic_castת����,ָ�벻Ϊ��,��ʱ��Դ�����߹�ͬʹ��,���ü���Ϊ2
  shared_ptr<circle> dptr3_1(new circle);
  shared_ptr<shape> dptr2_1 =
      dynamic_pointer_cast<shape>(dptr3_1);  // ����ת���� ����ת��,��ȫ��

  cout << "use count of dptr2_1 is now " << dptr2_1.use_count() << endl;  // 2
  cout << "use count of dptr3_1 is now " << dptr3_1.use_count() << endl;  // 2

  // shape* -> circle* ʹ��static_castת����,ָ��Ϊ��  ��dynamic_cast���,����ȫ
  shared_ptr<shape> sptr2(new shape);
  shared_ptr<circle> sptr1 = static_pointer_cast<circle>(sptr2);  // ����ת����

  cout << "use count of sptr1 is now " << dptr1.use_count() << endl;  // 0
  cout << "use count of sptr2 is now " << dptr2.use_count() << endl;  // 1

  // circle* -> circle*
  // ʹ��dynamic_castת����,ָ�벻Ϊ��,��ʱ��Դ�����߹�ͬʹ��,���ü���Ϊ2
  shared_ptr<shape> sptr3(new circle);
  //    shared_ptr<circle> sptr3(new circle);     //
  //    ������ߵ�ǰ��,�������һ����
  shared_ptr<circle> sptr1_1 =
      static_pointer_cast<circle>(sptr3);  // ����ת����

  cout << "use count of sptr1_1 is now " << sptr1_1.use_count() << endl;  // 2
  cout << "use count of sptr3 is now " << sptr3.use_count() << endl;      // 2

  // circle* -> circle*
  // ʹ��static_castת����,ָ�벻Ϊ��,��ʱ��Դ�����߹�ͬʹ��,���ü���Ϊ2
  // �ȼ���dynamic_cast
  shared_ptr<circle> sptr3_1(new circle);
  shared_ptr<shape> sptr2_1 =
      static_pointer_cast<shape>(sptr3_1);  // ����ת���� ����ת��,��ȫ��

  cout << "use count of sptr2_1 is now " << sptr2_1.use_count() << endl;  // 2
  cout << "use count of sptr3_1 is now " << sptr3_1.use_count() << endl;  // 2
  shared_ptr<const int> constV(new int);
  shared_ptr<int> s = const_pointer_cast<int>(constV);
  *s = 10;
  int a = reinterpret_pointer_cast<int>(s);
  cout << a << endl;
}