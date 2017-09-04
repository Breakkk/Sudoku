#ifndef STATE_H
#define STATE_H
#include <QString>

class State
{
public:
    State();
    QString style[9][9];
    QString text[9][9];
    int numButton[9][9];
    int numEnabled[9][9];
    bool numButtonUse[9][9][9];
    int record;
};

#endif // STATE_H
