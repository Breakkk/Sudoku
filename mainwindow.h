#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "option.h"
#include "select.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void judShow(int);
    ~MainWindow();

private slots:

    void on_start_clicked();

    void on_select_clicked();

    void on_option_clicked();

    void on_quit_clicked();

private:
    Ui::MainWindow *ui;
    Game game;
    Option option;
    Select select;
};

#endif // MAINWINDOW_H
