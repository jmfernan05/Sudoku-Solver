#include <iostream>
#include <array>
#include <string>
#include <stdlib.h>
#include "sudoku.h"

using namespace std;

int main()
{
	char rerun; //Set up rerun for the program
	do
	{
		Sudoku problem;
		cout << "Would you like to solve another puzzle? If yes, type y. Otherwise, enter any other letter: ";
		cin >> rerun;
	} while (rerun == 'y');
	return 0;
}
