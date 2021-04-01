#include <iostream>
using namespace std;

enum class shape_type {
  circle,
  triangle,
  rectangle,
};

class shape {
 public:
  shape() { cout << "shape" << endl; }

  virtual void print() { cout << "I am shape" << endl; }

  virtual ~shape() {}
};

class circle : public shape {
 public:
  circle() { cout << "circle" << endl; }

  void print() { cout << "I am circle" << endl; }
};

class triangle : public shape {
 public:
  triangle() { cout << "triangle" << endl; }

  void print() { cout << "I am triangle" << endl; }
};

class rectangle : public shape {
 public:
  rectangle() { cout << "rectangle" << endl; }

  void print() { cout << "I am rectangle" << endl; }
};

// ���ö�̬ ��ת �������ֵΪshape,����ڶ�����Ƭ���⡣
shape *create_shape(shape_type type) {
  switch (type) {
    case shape_type::circle:
      return new circle();
    case shape_type::triangle:
      return new triangle();
    case shape_type::rectangle:
      return new rectangle();
  }

  return nullptr;
}

class shape_wrapper {
 public:
  explicit shape_wrapper(shape *ptr = nullptr) : ptr_(ptr) {}

  ~shape_wrapper() { delete ptr_; }

  shape *get() const { return ptr_; }

 private:
  shape *ptr_;
};