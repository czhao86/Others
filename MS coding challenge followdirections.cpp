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
	string mt, lr;
	int n;
	int x = 0, y = 0;
	int A[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
	int dir = 0;
	while (!inFile.eof())
	{
		inFile >> mt;
		if (mt == "Move")
		{
			inFile >> n;
			x = x + n*A[dir][0];
			y = y + n*A[dir][1];
		}
		else if (mt == "Turn")
		{
			inFile >> lr;
			if (lr == "right") dir++;
			else dir--;
			if (dir == -1) dir = 3;
			if (dir == 4) dir = 0;
		}
	}
	outFile << x << ',' << y;
	cout << x << ',' << y << endl;
	inFile.close();
	outFile.close();
	return 0;
}
