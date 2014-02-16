#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<string> res;
	set<string> tmp;
	string in;
	cin >> in;
	for (int i = 0; i < in.length(); ++i)
	{
		for (int j = 1; j <= in.length() - i; ++j)
		{
			if (tmp.find(in.substr(i, j)) == tmp.end())
			{
				tmp.insert(in.substr(i, j));
				res.push_back(in.substr(i, j));
			}
		}
	}
	cout << res.size() << endl;
	return 0;
}
