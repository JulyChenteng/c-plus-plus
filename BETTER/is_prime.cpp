#include <iostream>
#include <cstddef>
#include <cmath>
#include <vector>

using namespace std;

bool is_prime(size_t num)
{
	if ((num & 1) != 0)
	{
		size_t limit = size_t(sqrt(num));
		for (size_t divisor = 3; divisor <= limit; divisor += 2)
		{
			if ((num % divisor) == 0)
			{
				return false;
			}
		}

		return true;
	}

	return (num == 2);
}

int main()
{
	vector<int> ivec{10, 20, 3, 2, 7, 9, 11, 13, 15, 17, 19, 400, 222, 177, 187, 199};

	for (auto i : ivec)
	{
		if (is_prime(i))
			cout << i << " ";
	}

	return 0;
}