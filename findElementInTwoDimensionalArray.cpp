#include <iostream>
#include <vector>

using namespace std;

bool findElementIn2DArray(vector<vector<int>> v, int target)
{
	int rows = v.size(), cols = v.at(0).size();

	for (int i=0, j=cols-1; (i < rows && i >= 0) && ( j >= 0 && j < cols);)
	{
		if (v.at(i).at(j) == target) 
		{
			return true;
		}
		else if (v.at(i).at(j) > target)
		{
			j--;
		}
		else
		{
			i++;
		}
	}

	return false;
}

int main()
{
	vector<vector<int>> array = {
		{1, 2, 8, 9},
		{2, 4, 9, 12},
		{4, 7, 10, 13},
		{6, 8, 11, 15}
	};

	
	for (auto i : array)
	{
		for (auto j : i) 
		{
			cout << j << " ";
		}
		cout << endl;
	}

	cout << findElementIn2DArray(array, 6) << endl;
	cout << findElementIn2DArray(array, 16) << endl;

	return 0;
}