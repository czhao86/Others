#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("ActualInput.txt");
	outFile.open("ActualOutput.txt");
	int n;
	double h, m, s;
	char dummy;
	inFile >> n;
	outFile << n << endl;
	for (int i = 0; i < n; ++i)
	{
		inFile >> h;
		inFile >> dummy;
		inFile >> m;
		inFile >> dummy;
		inFile >> s;
		double d1, d2, d3;
		d1 = h * 30 + m*0.5 + s*0.5 / 60;
		d2 = m * 360 / 60 + s * 360 / 60 / 60;
		d3 = s * 360 / 60;
		double A[3] = { d1 - d2, d1 - d3, d2 - d3 };
		for (int i = 0; i<3; ++i)
		{
			if (A[i]<0) A[i] = -A[i];
			if (A[i]>180) A[i] = 360 - A[i];
		}
		outFile << fixed;
		outFile.precision(2);
		outFile << A[0] << ", " << A[1] << ", " << A[2] << endl;
	}
	outFile.close();
	outFile.close();
	return 0;
}
