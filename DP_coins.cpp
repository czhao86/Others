#include <iostream>
using namespace std;

int main()
{
	int S = 11;
	int V[3] = {1,3,5};
	int res[11] = { 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
	res[0] = 0;
	for (int i = 1; i < S; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (V[j] <= i && res[i - V[j]]+1 < res[i])
				res[i] = res[i - V[j]] + 1;
		}
	}
	for (int i = 0; i < S; ++i)
	{
		cout << res[i] << ' ';
	}
	return 0;
}
