#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

void placeKing(int row, int* &pos, int n, int &ans)
{
	if (row == n)
	{
		ans++;
		return;
	}
	if (row == 0)
	{
		for (int x = 0; x < n; ++x)
		{
			pos[0] = x;
			placeKing(row+1, pos, n, ans);
		}
	}
	else if (row == 1)
	{
		for (int x = 0; x < n; ++x)
		{
			if (x > pos[row - 1] + 1 || x < pos[row - 1] - 1)
			{
				pos[1] = x;
				placeKing(row+1, pos, n, ans);
			}
		}
	}
	else if (row >= 2)
	{
		for (int i = 0; i < n; ++i)
		{
			if (i > pos[row - 1] + 1 || i < pos[row - 1] - 1)
			{
				bool test = true;
				for (int j = 0; j <= row - 2; ++j)
				{
					if (i == pos[j])
					{
							test = false;
							break;
					}
					
				}
				if (test == true)
				{
					pos[row] = i;
					placeKing(row + 1, pos, n, ans);
				}
			}
		}
	}
}

int main() {
	int t, n, k;
	cin >> t;
	for (int ii = 0; ii < t; ++ii)
	{
		cin >> n;
		cin >> k;
		int *pos = new int[n];
		memset(pos, -1, sizeof(pos));
		for (int i = 0; i < k; ++i)
			cin >> pos[i];
		int ans = 0;
		placeKing(k, pos, n, ans);
		cout << ans << endl;
	}
	return 0;
}
