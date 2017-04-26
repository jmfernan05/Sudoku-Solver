//
//  Sudoku.h
//  Sudoku Solver
//
//  Created by Jenifer Fernandes on 4/21/17.
//  Copyright © 2017 Jenifer Fernandes. All rights reserved.
//

#ifndef Sudoku_h
#define UNASSIGNED 0
#define N 9

#include <iostream>
#include <cstdlib>
#include <string>

class Sudoku
{
private:
    bool checkRow (int grid[N][N], int row, int num); //Checks the row
    bool checkCol (int grid[N][N], int col, int num); //Checks the column
    bool checkBox (int grid[N][N], int startRow, int startCol, int num); //Checks each box
    void PrintGrid(int grid [N][N]);
    void ReadFile (string inFile, int grid[N][N]);
    bool IsSafe(int grid [N][N], int&row, int&col, int num);
    bool FindUnassignedLocation (int grid [N][N], int &row, int&col);
    bool SolvePuzzle (int grid [N][N]);
    
public:
    Sudoku ();
    ~Sudoku() {}
    
};



#endif /* Sudoku_h */
