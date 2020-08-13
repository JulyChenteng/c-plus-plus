/*
	从标准输入读取几行输入，每行输入都要打印到标准输出上，前面要加上行号。
在编写这个程序时要试图让程序能够处理的输入行的长度没有限制。
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string line;
	vector<string> strVec;

	while (getline(cin, line))
		strVec.push_back(line);

	for (decltype(strVec.size()) i = 0; i < strVec.size(); i++)
	{
		cout << i << " " + strVec.at(i) << endl;
	}

	return 0;	
}
