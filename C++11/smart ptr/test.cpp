#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class CMember {
 public:
  CMember() {
    cout << "CMember constructor 1" << endl;
    cmember = 0;
  }
  CMember(int _cmember) {
    cout << "CMember constructor 2" << endl;
    cmember = _cmember;
  }
  CMember(CMember& obj) { cout << "CMember copy constructor" << endl; }
  CMember(const CMember& obj) { cout << "CMember copy constructor3" << endl; }

  CMember& operator=(CMember& obj) {
    cout << "CMember =" << endl;
    return *this;
  }

  CMember& operator=(int obj) {
    cout << "CMember =" << endl;
    return *this;
  }

  int cmember;
};

class MClass {
 public:
  MClass(CMember& _cm) : cm(_cm) {}
  //注意这里我们用的是引用，如果没有用引用，则会多一次copy构造函数的调用
  // MClass(CMember& _cm) { cm = _cm; }

  CMember cm;
};

#pragma pack(4)

struct test {
  char a;
  short b;
  char c;
};

int main() {
  //	vector<unique_ptr<int>> v(10);
  /* vector<auto_ptr<int>> u(10);
  u.push_back(new int(5));

  vector<auto_ptr<int>> v(10);
  int i = 0;
  for (; i < 10; i++) {
    v[i] = auto_ptr<int>(new int(i));
  } */

  CMember c1(1);   // 2
  CMember c2 = 1;  // 2

  CMember c3;  // 1
  c3 = 1;      //=

  MClass m1(c1);
  MClass m2 = c2;

  test a;
  cout << sizeof(a) << endl;

  return 0;
}
