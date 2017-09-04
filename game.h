#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QObject>
#include <QSignalMapper>
#include <QLayoutItem>
#include <QLayout>
#include <QTimer>
#include <QTime>
#include <QPixmap>
#include <QPalette>
#include <QDebug>
#include <vector>
#include <string>
#include <QString>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <set>
#include "level.h"
#include "state.h"
#include "pause.h"
#include "solver.h"
#include "win.h"
#include "generator.h"


namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    void check();
    void init(int);
    ~Game();

    int on_off = 0;

    QTimer *timer;
    QTime *timeRec;
    void SameGrid(int, int);
    bool numButtonUse[9][9][9];
    int numButton[9][9];
    int numEnabled[9][9];
    int levelSet = 0;
    int Level[11][9][9] = {
        {   //1
            {3,6,9,0,5,2,4,7,8},
            {8,5,0,6,7,4,9,3,1},
            {7,1,4,3,0,8,2,6,5},
            {6,8,3,9,2,7,1,5,4},
            {5,9,7,4,1,6,8,2,0},
            {0,2,1,8,3,5,6,9,7},
            {1,3,8,7,6,9,0,4,2},
            {2,4,0,5,8,3,7,1,9},
            {9,0,5,2,4,1,3,0,6}
        },
        {   //2
            {2, 0, 8, 3, 0, 0, 0, 9, 4},
            {5, 0, 7, 6, 0, 2, 8, 0, 1},
            {1, 3, 0, 0, 0, 9, 5, 0, 6},
            {0, 7, 0, 0, 0, 0, 2, 0, 0},
            {0, 0, 0, 0, 7, 3, 0, 1, 0},
            {8, 1, 0, 0, 2, 4, 0, 0, 7},
            {3, 0, 0, 1, 6, 0, 0, 7, 2},
            {0, 4, 0, 2, 9, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 6, 0}
        },
        {   //3
            {0,0,0,0,5,7,4,0,2},
            {6,0,7,0,0,0,1,0,5},
            {3,0,5,4,6,0,0,0,0},
            {0,0,2,0,0,4,0,1,3},
            {4,0,0,5,8,3,0,0,9},
            {0,3,0,9,1,0,0,0,0},
            {0,0,0,0,9,8,0,5,0},
            {5,0,0,2,3,6,0,0,1},
            {1,6,0,7,0,0,3,0,0}
        },
        {   //4
            {0,7,0,0,1,6,0,9,0},
            {0,0,0,0,0,0,0,0,0},
            {0,9,0,7,3,0,0,6,0},
            {0,3,2,0,0,0,0,0,7},
            {9,0,0,4,2,0,1,0,3},
            {0,0,0,0,0,1,0,0,9},
            {3,0,0,8,0,0,0,0,0},
            {8,0,5,0,9,7,0,0,1},
            {7,0,0,0,0,0,5,8,0}
        },
        {   //5
            {6,0,0,0,0,0,0,0,2},
            {0,4,0,8,0,6,0,3,0},
            {1,0,0,0,0,0,0,0,7},
            {0,9,1,6,0,2,7,0,0},
            {0,8,0,1,9,0,2,0,0},
            {5,0,2,3,0,0,0,0,0},
            {0,0,0,0,0,4,3,0,5},
            {0,0,5,0,3,9,0,2,0},
            {0,0,9,5,0,8,1,7,0}
        },
        {   //6
            {0,0,0,0,0,0,0,7,6},
            {6,8,0,0,0,0,0,5,4},
            {5,3,0,0,0,0,0,0,0},
            {0,5,9,0,8,6,0,0,0},
            {1,0,6,0,0,3,0,0,0},
            {0,0,0,0,0,2,4,0,9},
            {4,0,3,2,0,0,0,0,0},
            {0,0,0,7,0,0,5,0,3},
            {0,0,0,6,3,0,8,4,0}
        },
        {   //7
            {0,0,0,1,0,0,2,6,0},
            {7,0,0,0,3,0,0,0,0},
            {3,0,2,0,8,0,4,0,0},
            {0,0,0,4,0,8,0,0,1},
            {0,3,5,0,0,0,9,4,0},
            {2,0,0,3,0,5,0,0,0},
            {0,0,6,0,5,0,7,0,9},
            {0,0,0,0,4,0,0,0,8},
            {0,5,7,0,0,9,0,0,0}
        },
        {   //8
            {0,0,0,7,0,2,0,0,0},
            {1,0,0,0,4,0,0,0,7},
            {6,5,0,0,0,0,0,9,4},
            {4,7,0,8,0,1,0,6,2},
            {0,0,0,0,0,0,0,0,0},
            {5,8,0,2,0,9,0,1,3},
            {8,6,0,0,0,0,0,7,5},
            {9,0,0,0,6,0,0,0,8},
            {0,0,0,9,0,8,0,0,0}
        },
        {   //9
            {0,0,9,7,0,0,0,0,0},
            {5,0,0,0,0,2,7,0,9},
            {8,0,0,0,1,0,0,0,6},
            {0,0,1,6,0,0,4,0,5},
            {0,0,0,0,4,0,0,0,0},
            {7,0,6,0,0,8,2,0,0},
            {4,0,0,0,9,0,0,0,8},
            {6,0,2,3,0,0,0,0,4},
            {0,0,0,0,0,7,9,0,0}
        },
        {   //10
            {3,0,2,7,0,0,0,0,9},
            {0,0,8,0,0,0,0,4,5},
            {0,0,4,0,0,1,3,0,0},
            {0,0,0,0,5,9,0,0,0},
            {0,9,0,0,3,0,0,6,0},
            {0,0,0,2,6,0,0,0,0},
            {0,0,1,4,0,0,2,0,0},
            {2,6,0,0,0,0,1,0,0},
            {4,0,0,0,0,2,5,0,3}
        },
        {
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {}
        }
    };


private slots:
    void on_pushButton_clicked();
    void on_gridbutton_clicked(int);
    void showtime();
    void on_replay_clicked();

    void on_num_clicked(int);

    void on_stopTimer_clicked();

    void on_Submit_clicked();

    void on_Undo_clicked();

    void on_Redo_clicked();

    void Hint_click();

    void on_Del_clicked();

    void Lab_click();

signals:


private:
    Ui::Game *ui;
    QPushButton *button[9][9];
    QPushButton *num[9];
    QSignalMapper *signalmapper;
    QSignalMapper *nummapper;
    std::vector<State> UndoList;
    std::vector<State> RedoList;
    std::vector<int> numStore[9][9];
    int stopbutton = 1;
    int record = 0;
    Pause pause;
    QPushButton *Hint;
    QPushButton *Lab;
    void addUndo();
    Generator gen;
};


#endif // GAME_H
