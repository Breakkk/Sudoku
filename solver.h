#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>

class Data
{
public:
    Data();
    ~Data();
    int data[9][9];
};

class Solver
{
public:
    Solver(/*int ***/);
    Data solve();
    Data data;

private:
    bool jud_row_col(int, int, int);
    bool jud_grid(int, int, int);
    bool DFS(int);
    int sum_solve = 0;
};

#endif // SOLVER_H
