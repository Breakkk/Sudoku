#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #B0E2FF");
    this->game.setStyleSheet("background-color: #B0E2FF");
    this->select.setStyleSheet("background-color: #B0E2FF");
    this->option.setStyleSheet("background-color: #B0E2FF");
    this->setWindowTitle("Sudoku");
    ui->start->setFixedSize(200, 65);
    ui->select->setFixedSize(200, 65);
    ui->option->setFixedSize(200, 65);
    ui->quit->setFixedSize(200, 65);
    ui->option->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    this->hide();
    game.resize(this->size());
    game.timeRec->setHMS(0, 0, 0, 0);
    game.levelSet = 0;
    game.show();
    game.on_off = 1;
    game.exec();
    this->show();
    qDebug()<<"999";
}

void MainWindow::on_select_clicked()
{
    this->hide();
    select.resize(this->size());
    select.show();
    select.on_off = 1;
    select.exec();
    this->show();
}

void MainWindow::on_option_clicked()
{
    this->hide();
    option.resize(this->size());
    option.show();
    option.on_off = 1;
    option.exec();
    this->show();
}

void MainWindow::on_quit_clicked()
{
    this->close();
}

void MainWindow::judShow(int index)
{
    if(index == 0)
        this->show();
    else
        return ;
}
