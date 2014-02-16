#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cout << a[i];
	int in;
	if (2 * a[1] == a[0] + a[2])
	{
		in = a[1] - a[0];
		for (int i = 1; i < n; ++i)
		{
			if (a[i] - a[i - 1] != in)
			{
				cout << a[i - 1]+in << endl;
				break;
			}
		}
	}
	else
	{
		in = a[3] - a[2];
		for (int i = 3; i >= 0; --i)
		{
			if (a[i] - a[i - 1] != in)
			{
				cout << a[i] - in << endl;
				break;
			}
		}
	}
	return 0;
}
