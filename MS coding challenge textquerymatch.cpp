#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("ActualInput.txt");
	outFile.open("ActualOutput.txt");
	int nn;
	string dummy;
	inFile >> nn;
	outFile << nn << endl;
	getline(inFile, dummy);
	for (int j = 0; j < nn; ++j)
	{
		int max = 0;
		bool ans = false;
		string str1, str2;
		getline(inFile, str1);
		getline(inFile, str2);
		int m = str1.length();
		int n = str2.length();
		for (int i = 0; i < m; ++i)
		{
			if (str1[i] >= 'A' && str1[i] <= 'Z') str1[i] += 32;
		}
		for (int i = 0; i < n; ++i)
		{
			if (str2[i] >= 'A' && str2[i] <= 'Z') str2[i] += 32;
		}
		vector<vector<int>> dp(m, vector<int>(n, 0));
		if (str1[0] == str2[0]) dp[0][0] = 1;
		for (int i = 1; i < n; ++i)
		{
			if (str2[i - 1] == ' ' &&str2[i] == str1[0]) dp[0][i] = 1;
		}
		for (int i = 1; i < n; ++i)
		{
			if (str2[i] == ' ' &&dp[0][i - 1] == 1) dp[0][i] = 1;
		}

		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (str2[j] == ' ' &&dp[i][j - 1] >0) dp[i][j] = dp[i][j-1];
				if (str1[i] == str2[j] && dp[i - 1][j - 1]>0) dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j]>max) max = dp[i][j];
			}
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << dp[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		if (max==m) outFile << "true" << endl;
		else outFile << "false" << endl;
	}
	outFile.close();
	outFile.close();
	return 0;
}
