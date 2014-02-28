#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <ctime>
using namespace std;

int main()
{
	ofstream outFile;
	outFile.open("boxrandom.inj");
	double x_start = -0.00006, x_end = 0.00006;
	int x_count = 4;
	double y_start = -0.00006, y_end = 0.00006;
	int y_count = 4;
	double z_start = 0, z_end = 0.000006;
	int z_count = 1;
	int x_vel = 0, y_vel = 0, z_vel = 0;
	double diameter = 0.0000001;
	double T = 300.00;
	double mf = 1e-20;
	srand(time(NULL));
	for (int i = 0; i < 20; ++i)
	{
		outFile << "((";
		outFile << (double)rand() / RAND_MAX*0.00012 - 0.00006 << ' ';
		outFile << (double)rand() / RAND_MAX*0.00012 - 0.00006 << ' ';
		outFile << (double)rand() / RAND_MAX*0.000006 << ' ';
		outFile << x_vel << ' ' << y_vel << ' ' << z_vel << ' ' << diameter << ' ' << T << ' ' << mf << ") " << i << " )" << endl;
	}
	outFile.close();
	return 0;
}
