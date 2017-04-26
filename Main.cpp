#include <iostream>
#include <array>
#include <string>
#include <stdlib.h>
#include "sudoku.h"

using namespace std;
void ReadFile(string filename, int grid[N][N])
{
	int i, j;
	ifstream inFile;
	inFile.open("samplesudoku1.txt");

	if (inFile.fail())
	{
		cout << "cannot open file"<<endl;
		exit(1);
	}

	if (inFile.is_open())
	{
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				inFile >> grid[i][j];
			}
		}
		inFile.close();
	}
}

int main()
{
	Sudoku problem;
	int grid[9][9];
	string filename = "samplesudoku1.txt";
	ReadFile(filename, grid);
	bool checkRow(grid);
	bool checkCol(grid);
	bool checkBox(grid);
	bool IsSafe(grid);
	bool FindUnassignedLocation(grid);
	bool SolvePuzzle(grid);
	problem.PrintGrid(grid);
	return 0;
}
