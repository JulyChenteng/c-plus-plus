#include <iostream>
using namespace std;
#include <thread>

#if 0
void func()
{
}

int main()
{
	std::thread t(func);
	cout << t.get_id() << endl;
	cout << std::thread::hardware_concurrency() << endl;

	return 0;
}
#endif
