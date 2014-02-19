#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main()
{

	ifstream inFile;
	ofstream outFile;
	inFile.open("ActualInput.txt");
	outFile.open("ActualOutput.txt");
	while (!inFile.eof())
	{
		string tmp, st;
		char n;
		bool is = true;
		getline(inFile, tmp);
		st = tmp.substr(0, tmp.length() - 2);
		n = tmp[tmp.length() - 1];
		outFile << tmp;
		int step = n - '0';
		for (int i = 0; i < st.length() / 2; i = i + step)
		{
			if (st.substr(i, step) != st.substr(st.length() - i - step, step))
			{
				is = false;
				break;
			}
		}
		if (!inFile.eof()) outFile << '|' << is << endl;
		else outFile << '|' << is ;
	}
	inFile.close();
	outFile.close();
	return 0;
}
