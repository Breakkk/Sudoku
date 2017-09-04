#include "pause.h"
#include "ui_pause.h"

Pause::Pause(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pause)
{
    ui->setupUi(this);
    ui->pic->setFixedSize(500, 500);
    ui->label->setFixedSize(30, 500);
//    ui->pic->setPixmap(QPixmap(":/huaji2.png"));
    ui->pic->setScaledContents(true);
    this->setWindowTitle("Pause");
}

Pause::~Pause()
{
    delete ui;
}

void Pause::on_continue_2_clicked()
{
    this->close();
}
