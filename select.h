#ifndef SELECT_H
#define SELECT_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QString>
#include <QSignalMapper>
#include "game.h"


namespace Ui {
class Select;
}

class Select : public QDialog
{
    Q_OBJECT

public:
    explicit Select(QWidget *parent = 0);
    int on_off = 0;
    ~Select();

private slots:
    void on_pushButton_clicked();
    void doclick(int);
    void on_sran_clicked();

    void on_ran1_clicked();

    void on_ran3_clicked();

private:
    Ui::Select *ui;
    void LevelSet(int);
    QPushButton *button[10];
    QSignalMapper *signal;
    Game game;
    Generator gen;
};

#endif // SELECT_H
