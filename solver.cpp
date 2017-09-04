#include "solver.h"

Data::Data()
{

}

Data::~Data()
{

}

Solver::Solver(/*int** tmp*/)
{
//    for(int i = 0; i < 9; i++)
//    {
//        for(int j = 0; j < 9; j++)
//        {
//            data.data[i][j] = tmp[i][j];
//        }
//    }
}

Data Solver::solve()
{
    DFS(sum_solve);
    sum_solve = 0;
    return data;
}

bool Solver::jud_row_col(int x, int y, int index)
{
    for(int i = 0; i < 9; i++)
    {
        if(data.data[x][i] == index || data.data[i][y] == index)
            return false;
    }
    return true;
}

bool Solver::jud_grid(int x, int y, int index)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(x/3 == i/3 && y/3 == j/3)
            {
                if(data.data[i][j] == index)
                    return false;
            }
        }
    }
    return true;
}

bool Solver::DFS(int tmp)
{
    if(tmp > 80)
        return true;
    int x = tmp/9;
    int y = tmp%9;
    if(data.data[x][y] == 0)
    {
        for(int i = 1; i < 10; i++)
        {
            if(jud_row_col(x, y, i) && jud_grid(x, y, i))
            {
                data.data[x][y] = i;
                if(DFS(tmp + 1))
                    return true;
                data.data[x][y] = 0;
            }
        }
    }
    else
        return DFS(tmp + 1);
    return false;
}
