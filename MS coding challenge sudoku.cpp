#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) {
		bool found = false;
		_solveSudoku(board, 0, found);
	}
	void _solveSudoku(vector<vector<char> > &board, int num, bool &found)
	{
		if (num == 81)
		{
			found = true;
			return;
		}
		int r = num / 9;
		int c = num % 9;
		if (board[r][c] != 'x') _solveSudoku(board, num + 1, found);
		else
		{
			vector<bool> tmp(10, false);
			for (int i = 0; i < 9; ++i)
			{
				if (board[r][i] != 'x') tmp[board[r][i] - '0'] = true;
				if (board[i][c] != 'x') tmp[board[i][c] - '0'] = true;
			}
			int rr = r, cc = c;
			while (rr % 3 != 0) rr--;
			while (cc % 3 != 0) cc--;
			for (int i = rr; i < rr + 3; ++i)
			{
				for (int j = cc; j < cc + 3; ++j)
				{
					if (board[i][j] != 'x') tmp[board[i][j] - '0'] = true;
				}
			}
			for (int i = 1; i < 10; ++i)
			{
				if (!tmp[i])
				{
					board[r][c] = '0' + i;
					_solveSudoku(board, num + 1, found);
					if (found) break;
					board[r][c] = 'x';
				}
			}
		}
	}
};

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("ActualInput.txt");
	outFile.open("ActualOutput.txt");
	vector<vector<char>> board(9, vector<char>(9, 'x'));
	Solution sol;
	for (int n = 0; n < 2; ++n)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				inFile >> board[i][j];
			}
		}
		sol.solveSudoku(board);
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				outFile << board[i][j];
				if (j == 8 && i != 8) outFile << endl;
				if (j != 8) outFile << ' ';
			}
		}
		if (n != 1) outFile << endl << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}
