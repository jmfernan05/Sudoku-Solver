#ifndef Sudoku_h
#define UNASSIGNED 0
#define N 9

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

class Sudoku
{
public:
	bool checkRow(int grid[N][N], int row, int num); //Checks the row
	bool checkCol(int grid[N][N], int col, int num); //Checks the column
	bool checkBox(int grid[N][N], int startRow, int startCol, int num); //Checks each box
	void PrintGrid(int grid[N][N]);
	void DisplayPuzzle(int grid[N][N]);
	void ReadFile(std::string filename, int grid[N][N]);
	bool IsSafe(int grid[N][N], int&row, int&col, int num);
	bool FindUnassignedLocation(int grid[N][N], int &row, int&col);
	bool SolvePuzzle(int grid[N][N]);
	Sudoku();
	~Sudoku() {}

};



#endif /* Sudoku_h */