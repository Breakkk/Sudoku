#include "option.h"
#include "ui_option.h"

Option::Option(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Option)
{
    ui->setupUi(this);
    this->setWindowTitle("Option");
}

Option::~Option()
{
    delete ui;
}

void Option::on_pushButton_clicked()
{
    this->close();
}
