//! g++ dm02.cpp -I "F:\\Open Source\\boost_1_73_0"
//! 基础概念：左值、右值、引用折叠

//! 万能引用
#if 0
#include <boost/type_index.hpp>
#include <iostream>

using namespace std;
using boost::typeindex::type_id_with_cvr;  

template<typename T>
void PrintType(T&& param)
{
    // 利用Boost库打印模板推导出来的 T 类型
	cout << "T type: " << type_id_with_cvr<T>().pretty_name() << endl; 
    
    // 利用Boost库打印形参的类型
	cout << "param type:" << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}

int main()
{
	int a = 0;                              // 左值
	PrintType(a);                           // 传入左值

	int &lvalue_refence_a = a;              // 左值引用
	PrintType(lvalue_refence_a);            // 传入左值引用

	PrintType(int(2));                      // 传入右值
}
#endif

/*
output:
        T type: int&
        param type:int&
        T type: int&
        param type:int&
        T type: int
        param type:int&&
*/

//! 完美转发
#if 0
#include <iostream>
using namespace std;

// 接收右值的函数f()
template<typename T>
void f(T &&)
{
	cout << "f(T &&)" << endl;
}

//! 接收左值的函数 f()
template<typename T>
void f(T &)
{
	cout << "f(T &)" << endl;
}

// 万能引用，转发接收到的参数 param
template<typename T>
void PrintType(T&& param)
{
	f(param); // 将参数param转发给函数 void f()
}

int main(int argc, char *argv[])
{
	int a = 0;
	PrintType(a);		//传入左值
	PrintType(int(0));	//传入右值
}
#endif

#if 0
#include <iostream>
using namespace std;

class Copyable {
public:
    Copyable() { cout << "normal" << endl; }
    Copyable(const Copyable &o) {
        cout << "Copied" << endl;
    }
};
Copyable ReturnRvalue() {
    return Copyable(); //返回一个临时对象
}
void AcceptVal(Copyable a) {

}
void AcceptRef(const Copyable& a) {

}

int main() {
    cout << "pass by value: " << endl;
    AcceptVal(ReturnRvalue()); // 应该调用两次拷贝构造函数
    cout << "pass by reference: " << endl;
    AcceptRef(ReturnRvalue()); //应该只调用一次拷贝构造函数
}
#endif

//! g++ dm02.cpp -I "F:\\Open Source\\boost_1_73_0"
/*
output:
        pass by value:
        normal
        pass by reference:
        normal
*/
//! g++ dm02.cpp -I "F:\\Open Source\\boost_1_73_0" -fno-elide-constructors
//! 去除编译器优化(RVO/NRVO, RVO, Return Value Optimization
//! 返回值优化，或者NRVO， Named Return Value Optimization)
/*
output:
        pass by value:
        normal
        Copied
        Copied
        pass by reference:
        normal
        Copied
*/

#if 0

#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

template<typename T>
void f(T&& param){
    if (std::is_same<string, T>::value)
        std::cout << "string" << std::endl;
    else if (std::is_same<string&, T>::value)
        std::cout << "string&" << std::endl;
    else if (std::is_same<string&&, T>::value)
        std::cout << "string&&" << std::endl;
    else if (std::is_same<int, T>::value)
        std::cout << "int" << std::endl;
    else if (std::is_same<int&, T>::value)
        std::cout << "int&" << std::endl;
    else if (std::is_same<int&&, T>::value)
        std::cout << "int&&" << std::endl;
    else
        std::cout << "unkown" << std::endl;
}

int main()
{
    int x = 1;
    f(1); // 参数是右值 T推导成了int, 所以是int&& param, 右值引用
    f(x); // 参数是左值 T推导成了int&, 所以是int&&& param, 折叠成 int&,左值引用
    int && a = 2;
    f(a); //虽然a是右值引用，但它还是一个左值， T推导成了int&
    string str = "hello";
    f(str); //参数是左值 T推导成了string&
    f(string("hello")); //参数是右值， T推导成了string
    f(std::move(str));//参数是右值， T推导成了string
}

/*
output:
	int
	int&
	int&
	string&
	string
	string
*/

#endif

#if 1
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class A {
 public:
  A(int i) {
    cout << "A default" << endl;
    str = i;
  }

  ~A() {}
  A(const A& other) : str(other.str) { cout << "A&" << endl; }

 public:
  int str;
};

int main() {
  vector<A> vec;
  vec.reserve(10);
  for (int i = 0; i < 3; i++) {
    // A a(i);      // 三次构造
    //vec.push_back(i);     // push前调用了3次构造函数,然后放入容器时placement new会再产生3次拷贝构造 右值引用
    vec.emplace_back(i);    // 一次拷贝构造函数都没有调用过，只有在placement new的时候产生三次构造
    // vec.emplace_back(A(i));  // 三次构造，三次拷贝构造
    // vec.push_back(A(i));     // 三次构造，三次拷贝构造  右值引用
    // vec.emplace_back(a);     // 三次拷贝构造  
    // vec.push_back(a);        // 三次拷贝构造           左值引用
  }
}

#endif

#if 0
#include <boost/type_index.hpp>
#include <iostream>

using namespace std;
using boost::typeindex::type_id_with_cvr;  

template<typename T>
void PrintType(T param)
{
    // 利用Boost库打印模板推导出来的 T 类型
	cout << "T type: " << type_id_with_cvr<T>().pretty_name() << endl; 
    
    // 利用Boost库打印形参的类型
	cout << "param type:" << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}

int main()
{
	int a = 0;                              // 左值
	PrintType(a);                           // 传入左值

	int &lvalue_refence_a = a;              // 左值引用
	PrintType(lvalue_refence_a);            // 传入左值引用

	PrintType(int(2));                      // 传入右值

    const char* const ptr = "fun test";
    PrintType(ptr);
}
#endif
