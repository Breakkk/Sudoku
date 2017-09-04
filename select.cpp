#include "select.h"
#include "ui_select.h"

Select::Select(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Select)
{
    ui->setupUi(this);
    this->setWindowTitle("Select");
    signal = new QSignalMapper;
    for(int i = 0; i < 10; i++)
    {
        button[i] = new QPushButton(QString::number(i + 1));
        connect(button[i], SIGNAL(clicked()), signal, SLOT(map()));
        ui->gridLayout->addWidget(button[i], i/5, i%5);
        signal->setMapping(button[i], i);
    }
    connect(signal, SIGNAL(mapped(int)), this, SLOT(doclick(int)));
    button[0]->setStyleSheet("color:#CDC5BF; font: 75 36pt 'Agency FB';");
    button[1]->setStyleSheet("color:#CDBA96; font: 75 36pt 'Agency FB';");
    button[2]->setStyleSheet("color:#CDB38B; font: 75 36pt 'Agency FB';");
    button[3]->setStyleSheet("color:#CD9B9B; font: 75 36pt 'Agency FB';");
    button[4]->setStyleSheet("color:#CD919E; font: 75 36pt 'Agency FB';");
    button[5]->setStyleSheet("color:#CD8162; font: 75 36pt 'Agency FB';");
    button[6]->setStyleSheet("color:#CD6839; font: 75 36pt 'Agency FB';");
    button[7]->setStyleSheet("color:#CD5C5C; font: 75 36pt 'Agency FB';");
    button[8]->setStyleSheet("color:#CD3700; font: 75 36pt 'Agency FB';");
    button[9]->setStyleSheet("color:#CD2626; font: 75 36pt 'Agency FB';");

}

void Select::doclick(int index)
{
    game.setStyleSheet("background-color: #B0E2FF");
    game.timeRec = new QTime(0, 0, 0, 0);
    game.timer->start();
    game.levelSet = index;
    game.init(game.levelSet);
    game.show();
    game.exec();
}

Select::~Select()
{
    delete ui;
}

void Select::on_pushButton_clicked()
{
    this->close();
}

void Select::on_sran_clicked()
{
    LevelSet(20);
}

void Select::on_ran1_clicked()
{
    LevelSet(10);
}

void Select::on_ran3_clicked()
{
    LevelSet(80);
}

void Select::LevelSet(int dif)
{
    game.setStyleSheet("background-color: #B0E2FF");
    gen.setDif(dif);
    Data ranLev = gen.getAns();
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            game.Level[10][i][j] = ranLev.data[i][j];
        }
    }
    game.timeRec = new QTime(0, 0, 0, 0);
    game.timer->start();
    game.levelSet = 10;
    game.init(game.levelSet);
    game.show();
    game.exec();
}
