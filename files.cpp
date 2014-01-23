#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string s = "FFF-0", e = ".1-21-00005";
	string f;
	double a[120][1000];
	int nn = 1000;
	int num;
	for (int i = 11; i < 131; ++i)
	{
		num = i - 11;
		if (i<100)
			f = s + "0" + to_string(i) + e;
		else
			f = s + to_string(i) + e;
		char *fname = new char[f.size() + 1];
		fname[f.size()] = 0;
		memcpy(fname, f.c_str(), f.size());
		freopen(fname, "r", stdin);
		string tmp;
		for (int j = 0; j < 5; ++j)
		{
			cin >> tmp;
		}
		string temp;
		for (int k = 0; k < nn; ++k)
		{
			cin >> temp;
			cin >> temp;
			cin >> temp;
			cin >> temp;
			cin >> a[num][k];
		}
		fclose(stdin);
	}
	//for (int m = 0; m < 120; ++m)
	//{
	//	for (int i = 0; i < 50; ++i)
	//		cout << a[m][i] << ' ';
	//	cout << endl;
	//}
	double res[1000];
	memset(res, 0, nn*8);
	for (int i = 0; i < nn; ++i)
	{
		for (int j = 0; j < 120; ++j)
			res[i] += a[j][i];
	}
	for (int i = 0; i < nn; ++i)
		cout << res[i] << ' ';
	cout << endl;
	ofstream outputFile;
	outputFile.open("result.txt");
	for (int i = 0; i < nn; ++i)
		outputFile << res[i] << endl;
	outputFile.close();

	return 0;
}
