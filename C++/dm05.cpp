#include <iostream>
using namespace std;

class A {
 public:
  A() : a(1){};
  virtual void printA() { cout << a << endl; }
  int a;
};

#if 0
class B : public A {
 public:
  void printB() { cout << "from B" << endl; }
};

class C : public A {
 public:
  void printB(int v) { cout << "from C" << endl; }
};
#endif

#if 1
class B : virtual public A {
 public:
  void printB() { cout << "from B" << endl; }
};

class C : virtual public A {
 public:
  void printB(int v) { cout << "from C" << endl; }
};
#endif

class D : public B, public C {};



int main(int argc, char* argv[]) {
  D d;
  B b;
  cout << sizeof(d);
  //d.printB();
}
