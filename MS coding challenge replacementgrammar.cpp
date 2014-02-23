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
	queue<string> sta, stb;
	string tmp;
	while (!inFile.eof())
	{
		int i = 0;
		getline(inFile, tmp);
		if (tmp.empty()) break;
		while (tmp[i] != '|') i++;
		string str1 = tmp.substr(0, i);
		string str2 = tmp.substr(i + 1, tmp.length() - i - 1);
		sta.push(str1);
		stb.push(str2);
	}
	while (tmp.empty())  getline(inFile, tmp);
	while (!sta.empty())
	{
		string top1 = sta.front();
		string top2 = stb.front();
		sta.pop(), stb.pop();
		size_t found = tmp.find(top1);
		while (found != string::npos)
		{
			tmp.replace(found, top1.length(), top2);
			found = tmp.find(top1,found+top2.length());
		}
	}
	outFile << tmp << endl;
	inFile.close();
	outFile.close();
	return 0;
}
