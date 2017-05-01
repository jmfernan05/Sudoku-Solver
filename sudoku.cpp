#include <iostream>
#include "sudoku.h"
using namespace std;


//Check Row to see if the assigned entry matches the number in the row
bool Sudoku::checkRow(int grid[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}

//Check the column to see if the assigned entry matches the number in the column
bool Sudoku::checkCol(int grid[N][N], int col, int num) {
	for (int row = 0; row < N; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}

//Checks the 3X3 box to see if the assigned entry matches the given number
bool Sudoku::checkBox(int grid[N][N], int startRow, int startCol, int num) {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + startRow][col + startCol] == num)
				return true;
	return false;
}

//Function that seraches the grid to see if there are any unassigned spots
bool Sudoku::FindUnassignedLocation(int grid[N][N], int &row, int&col) {
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == UNASSIGNED)
				return true;
	return false;
}

//checks to see if it is illegl to assign a number to the given row and col at the location
//by check if a number is not already placed in row and column and 3X3 box
bool Sudoku::IsSafe(int grid[N][N], int&row, int&col, int num) {
	return !checkRow(grid, row, num) &&
		!checkCol(grid, col, num) &&
		!checkBox(grid, row - row % 3, col - col % 3, num);
}

//Reads the grid and assign values to unassigned locations and checks to if the assigned
//number is valid
bool Sudoku::SolvePuzzle(int grid[N][N]) {
	int row, col;

	//If the grid is filled then the program is done
	if (!FindUnassignedLocation(grid, row, col))
		return true;

	//if there are uassigned values the program starts assigning numbers 1 through 9
	for (int num = 1; num <= 9; num++)
	{
		if (IsSafe(grid, row, col, num))
		{
			grid[row][col] = num; //Assign numbers

			if (SolvePuzzle(grid)) //return if success
				return true;
			else
				grid[row][col] = UNASSIGNED; //try again

		}
	}
	return false;
}

//Display the puzzle and replace 0 value with blank character
void Sudoku::DisplayPuzzle(int grid[N][N])
{
	for (int x = 0; x < 9; x++) //Row
	{
		cout << endl;
		for (int y = 0; y < 9; y++) //Column
		{
			if (grid[x][y] == UNASSIGNED)
				cout << (char)grid[x][y]; //Replace 0 with blank in the displayed puzzle
			else
				cout << grid[x][y];
			cout << "|";
		}
	}
	cout << endl;
}

//Read the text file line by line and input the file into the grid
void Sudoku::ReadFile(string filename, int grid[N][N])
{
	int i, j;
	ifstream inFile;
	inFile.open(filename);

	if (inFile.fail())
	{
		cout << "cannot open file" << endl;
		exit(1);
	}

	if (inFile.is_open())
	{
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				inFile >> grid[i][j]; //Input the file into the grid
			}
		}
		inFile.close();
	}
}


//Function to read the file
//void ReadFile(string filename, int grid[N][N])




Sudoku::Sudoku() {
	int grid[N][N];
	string filename;
	cout << "Please enter the file name:\n>"; //Ask for user input on the text filename
	cin >> filename;
	filename += ".txt"; //Eliminate the need to type the .txt
	ReadFile(filename, grid);
	DisplayPuzzle(grid);
	if (SolvePuzzle(grid) == true)
		DisplayPuzzle(grid);
	else
		printf("No solution exists");


}
