#include "win.h"
#include "ui_win.h"

Win::Win(QString time, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Win)
{
    ui->setupUi(this);
    ui->win->setText("Victory\n" + time);
    ui->win->setAlignment(Qt::AlignCenter);
    ui->win->setStyleSheet("color:black; font: 75 20pt 'Agency FB';");
}

Win::~Win()
{
    delete ui;
}

void Win::on_back_clicked()
{
    this->close();
}
