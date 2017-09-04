#include "generator.h"

Generator::Generator()
{
    srand((unsigned)time(NULL));
//    for(int i = 0; i < 9; i++)
//    {
//        for(int j = 0; j < 9; j++)
//        {
//            std::cout<<tmp.data[i][j]<<' ';
//        }
//        std::cout<<std::endl;
//    }
}

void Generator::chooseSeed()
{
    //int ran = rand() % 5;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            Basic.data[i][j] = ranSeed[i][j];
        }
    }
    tmp = Basic;
}

void Generator::changeCol()
{
    int gri = rand() % 3;
    int fir = rand() % 3;
    int sec = rand() % 3;
    while(fir == sec)
    {
        fir = rand() % 3;
        sec = rand() % 3;
    }
    for(int i = 0; i < 9; i++)
    {
        std::swap(tmp.data[i][gri * 3 + fir], tmp.data[i][gri * 3 + sec]);
    }
}

void Generator::changeRow()
{
    int gri = rand() % 3;
    int fir = rand() % 3;
    int sec = rand() % 3;
    while(fir == sec)
    {
        fir = rand() % 3;
        sec = rand() % 3;
    }
    for(int i = 0; i < 9; i++)
    {
        std::swap(tmp.data[gri * 3 + fir][i], tmp.data[gri * 3 + sec][i]);
    }
}

void Generator::changeGri()
{
    int fir_x = rand() % 3;
    int fir_y = rand() % 3;
    int sec_x = rand() % 3;
    int sec_y = rand() % 3;
    while(fir_x == sec_x && fir_y == sec_y)
    {
        fir_x = rand() % 3;
        fir_y = rand() % 3;
        sec_x = rand() % 3;
        sec_y = rand() % 3;
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::swap(tmp.data[fir_x * 3 + i][fir_y * 3 + j], tmp.data[sec_x * 3 + i][sec_y + j]);
        }
    }
}

void Generator::reCot()
{
    int cnt = 1000 + rand() % 20;
    int ran = 0;
    for(int i = 0; i < cnt; i++)
    {
        ran = rand() % 2;
        if(ran == 1)
            changeCol();
        else
            changeRow();
    }
}

void Generator::ranDig()
{
    reCot();

    for(int i = 0; i < Difficulty; i++)
    {
        while(true)
        {
            int x = rand()%9;
            int y = rand()%9;
            int rec = tmp.data[x][y];
            if(rec == 0)
                continue;
            tmp.data[x][y] = 0;
//            sol.data = tmp;
//            sol.data = sol.solve();
            break;
//            for(int i = 0; i < 9; i++)
//            {
//                for(int j = 0; j < 9; j++)
//                {
//                    if(sol.data.data[i][j] == 0)
//                    {
//                        tmp.data[x][y] = rec;
//                        continue;
//                    }
//                    else
//                        break;
//                }
//            }
        }
    }

}

void Generator::check()
{

}

Data Generator::getAns()
{
    chooseSeed();
    ranDig();
    return tmp;
}
