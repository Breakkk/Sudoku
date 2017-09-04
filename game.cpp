#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    //ui->Time->setStyleSheet("color:black");
    ui->clock->setFixedSize(25,25);
    ui->clock->setPixmap(QPixmap(":/clock1.png"));
    ui->clock->setScaledContents(true);

    timeRec = new QTime(0, 0, 0, 0);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showtime()));
    timer->start(1000);
    init(levelSet);
    this->setWindowTitle("Game");
}

Game::~Game()
{
    delete ui;
}

void Game::on_pushButton_clicked()
{
    if(stopbutton == 0)
        return ;
    this->close();
}

void Game::SameGrid(int x, int y)
{
    //the same
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(button[i][j]->text() == button[x][y]->text() && numButton[i][j] == 1)
            {
                if(numEnabled[i][j] == 0)
                    button[i][j]->setStyleSheet("color:#9F79EE; font: 75 26pt 'Agency FB'; background-color:yellow");
                else
                    button[i][j]->setStyleSheet("color:	#CD661D; font: 75 26pt 'Agency FB'; background-color:yellow");
            }
        }
    }
    //border and the red  same
    for(int i = 0; i < 9; i++)
    {
        if(numButton[i][y] > 1)
            button[i][y]->setStyleSheet("color:	#CD661D; font: 75 10pt 'Agency FB'; border-left: 3px solid black; border-right: 3px solid black; border-top: 3px solid black; border-bottom: 3px solid black");
        else if(numEnabled[i][y] == 0)
            button[i][y]->setStyleSheet("color:	#9F79EE; font: 75 26pt 'Agency FB'; border-left: 3px solid black; border-right: 3px solid black; border-top: 3px solid black; border-bottom: 3px solid black");
        else
            button[i][y]->setStyleSheet("color:	#CD661D; font: 75 26pt 'Agency FB'; border-left: 3px solid black; border-right: 3px solid black; border-top: 3px solid black; border-bottom: 3px solid black");

        if(numButton[x][i] > 1)
            button[x][i]->setStyleSheet("color:	#CD661D; font: 75 10pt 'Agency FB'; border-left: 3px solid black; border-right: 3px solid black; border-top: 3px solid black; border-bottom: 3px solid black");
        else if(numEnabled[x][i] == 0)
            button[x][i]->setStyleSheet("color:	#9F79EE; font: 75 26pt 'Agency FB'; border-left: 3px solid black; border-right: 3px solid black; border-top: 3px solid black; border-bottom: 3px solid black");
        else
            button[x][i]->setStyleSheet("color:	#CD661D; font: 75 26pt 'Agency FB'; border-left: 3px solid black; border-right: 3px solid black; border-top: 3px solid black; border-bottom: 3px solid black");

        if(button[i][y]->text() == button[x][y]->text() && numButton[i][y] == 1)
        {
            if(numEnabled[i][y] == 0)
                button[i][y]->setStyleSheet("color:	#9F79EE; font: 75 26pt 'Agency FB'; background-color:red;");
            else
                button[i][y]->setStyleSheet("color:	#CD661D; font: 75 26pt 'Agency FB'; background-color:red;");
        }
        if(button[x][i]->text() == button[x][y]->text() && numButton[x][i] == 1)
        {
            if(numEnabled[x][i] == 0)
                button[x][i]->setStyleSheet("color:	#9F79EE; font: 75 26pt 'Agency FB'; background-color:red;");
            else
                button[x][i]->setStyleSheet("color:	#CD661D; font: 75 26pt 'Agency FB'; background-color:red;");
        }
    }
    //border and the red same with the same grid
    int grid_x = x/3;
    int grid_y = y/3;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(i/3 == grid_x && j/3 == grid_y)
            {
                if(numEnabled[i][j] == 0)
                    button[i][j]->setStyleSheet("color:	#9F79EE; font: 75 26pt 'Agency FB'; border-left: 3px solid #8B008B; border-right: 3px solid #8B008B; border-top: 3px solid #8B008B; border-bottom: 3px solid #8B008B");
                else if(numButton[i][j] > 1)
                    button[i][j]->setStyleSheet("color: #CD661D; font: 75 10pt 'Agency FB'; border-left: 3px solid #8B008B; border-right: 3px solid #8B008B; border-top: 3px solid #8B008B; border-bottom: 3px solid #8B008B");
                else
                    button[i][j]->setStyleSheet("color: #CD661D; font: 75 26pt 'Agency FB'; border-left: 3px solid #8B008B; border-right: 3px solid #8B008B; border-top: 3px solid #8B008B; border-bottom: 3px solid #8B008B");

                if(button[i][j]->text() == button[x][y]->text() && numButton[i][j] == 1)
                {
                    if(numEnabled[i][j] == 0)
                        button[i][j]->setStyleSheet("color:	#9F79EE; font: 75 26pt 'Agency FB'; background-color:red;");
                    else
                        button[i][j]->setStyleSheet("color:	#CD661D; font: 75 26pt 'Agency FB'; background-color:red;");
                }
            }
        }
    }
}

void Game::on_gridbutton_clicked(int index)
{
    if(stopbutton == 0)
        return ;
    record = index;
    int x = index/10;
    int y = index%10;
    //init
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(numEnabled[i][j] == 0)
                button[i][j]->setStyleSheet("color:	#9F79EE; font-size: 26pt; font-family:'Agency FB'; background-color:#B0E2FF;");
            else if(numButton[i][j] > 1)
                button[i][j]->setStyleSheet("color: #CD661D; font: 10pt 'Agency FB'; background-color:#B0E2FF;");
            else
                button[i][j]->setStyleSheet("color:	#CD661D; font:26pt 'Agency FB'; background-color:#B0E2FF;");
        }
    }

    SameGrid(x, y);

    if(numEnabled[x][y] == 0)
        button[x][y]->setStyleSheet("color:	#9F79EE; font: 75 26pt 'Agency FB'; background-color:#7FFF00");
    else if(numButton[x][y] > 1)
        button[x][y]->setStyleSheet("color:	#CD661D; font: 75 10pt 'Agency FB'; background-color:#7FFF00");
    else
        button[x][y]->setStyleSheet("color:	#CD661D; font: 75 26pt 'Agency FB'; background-color:#7FFF00");
}

void Game::on_replay_clicked()
{
    if(stopbutton == 0)
        return ;
    init(levelSet);
}

void Game::init(int index)
{/*
    QLayoutItem *item;
    while((item = layout()->takeAt(0)) != 0)
        delete item;*/

    ui->Level->setText("关卡:  " + QString::number(levelSet + 1));
    timeRec->setHMS(0, 0, 0, 0);

    UndoList.clear();
    RedoList.clear();

    signalmapper = new QSignalMapper(this);
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(Level[index][i][j] != 0)
            {
                button[i][j] = new QPushButton(QString::number(Level[index][i][j]));
                numButton[i][j] = 1;
                numEnabled[i][j] = 0;
                button[i][j]->setStyleSheet("color:	#9F79EE; font-size: 26pt; font-family:'Agency FB'; ");
            }
            else
            {
                button[i][j] = new QPushButton("");
                numButton[i][j] = 0;
                numEnabled[i][j] = 1;
                button[i][j]->setStyleSheet("color:	#CD661D; font-size: 26pt; font-family:'Agency FB'; ");
            }


            button[i][j]->setFixedSize(50, 50);
            ui->totalgrid->addWidget(button[i][j], i, j);
            connect(button[i][j], SIGNAL(clicked()), signalmapper, SLOT(map()));
            signalmapper->setMapping(button[i][j], i *  10 + j);
        }
    }
//    ui->totalgrid->setMargin(0);
    ui->totalgrid->setSpacing(1);
    connect(signalmapper, SIGNAL(mapped(int)), this, SLOT(on_gridbutton_clicked(int)));

    nummapper = new QSignalMapper(this);
    for(int i = 0; i < 9; i++)
    {
        num[i] = new QPushButton(QString::number(i + 1));
        num[i]->setStyleSheet("color:#8B636C; font: 75 20pt 'Agency FB'; ");
        if(i < 1)
        {
            ui->func_grid->addWidget(num[i], 0, i + 7);
        }
        else
        {
            ui->func_grid->addWidget(num[i], 1, i - 1);
        }
        connect(num[i], SIGNAL(clicked()), nummapper, SLOT(map()));
        nummapper->setMapping(num[i], i + 1);
    }
    connect(nummapper, SIGNAL(mapped(int)), this, SLOT(on_num_clicked(int)));

    //Hint:
    Hint = new QPushButton("Hint");
    ui->func_grid->addWidget(Hint, 0, 4);
    Hint->setStyleSheet("color:white; font: 75 20pt 'Agency FB';");
    connect(Hint, SIGNAL(clicked()), this, SLOT(Hint_click()));

    //Label:
//    Lab = new QPushButton("Lab");
//    ui->func_grid->addWidget(Lab, 0, 4);
//    Lab->setStyleSheet("color:white; font: 75 20pt 'Agency FB';");
//    connect(Lab, SIGNAL(clicked()), this, SLOT(Lab_click()));
}

void Game::on_num_clicked(int num)
{
    if(stopbutton == 0)
        return ;

    int x = record/10;
    int y = record%10;
    if(numEnabled[x][y] == 0 || numButton[x][y] == 9)
        return ;
    if(button[x][y]->text().indexOf(QString::number(num)) >= 0)
        return ;

    State tmp;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            tmp.style[i][j] = button[i][j]->styleSheet();
            tmp.text[i][j]  = button[i][j]->text();
            tmp.numButton[i][j] = numButton[i][j];
            tmp.numEnabled[i][j] = numEnabled[i][j];
//            tmp.numButtonUse= numButtonUse[9][9];
        }
    }
    tmp.record = record;
    UndoList.push_back(tmp);
    RedoList.clear();

//    std::string tmp = std::to_string(record) + ",add," + std::to_string(num);
//    UndoList.push_back(tmp);
//    numStore[x][y].push_back(num);
    if(numButton[x][y] > 0)
    {
        button[x][y]->setStyleSheet("color: #CD661D; font: 10pt 'Agency FB'; background-color:#7FFF00;");
        if(numButton[x][y] % 3 == 0)
        {
            button[x][y]->setText(button[x][y]->text() + "\n" + QString::number(num));
        }
        else
        {
            button[x][y]->setText(button[x][y]->text() + " " + QString::number(num));
        }
        numButton[x][y]++;
        on_gridbutton_clicked(record);
        return ;
    }
    else
    {
        button[x][y]->setText(QString::number(num));
        button[x][y]->setStyleSheet("color: #CD661D; font: 26pt 'Agency FB'; background-color:#7FFF00;");
    }
    numButton[x][y]++;
    on_gridbutton_clicked(record);
    return ;
}

void Game::showtime()
{
    *timeRec = timeRec->addSecs(1);
    QString tmp = timeRec->toString("hh:mm:ss");
    ui->Time->setText(timeRec->toString("hh:mm:ss"));
}

void Game::on_stopTimer_clicked()
{
//    if(stopbutton == 1)
//    {
//        timer->stop();
//        ui->stopTimer->setText("继续");
//        stopbutton = 0;
//    }
//    else
//    {
//        timer->start();
//        ui->stopTimer->setText("暂停");
//        stopbutton = 1;
//    }

    if(stopbutton == 0)
        return ;
    addUndo();
    timer->stop();
    stopbutton = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            button[i][j]->setText("");
            button[i][j]->setStyleSheet("");
            numEnabled[i][j] = 0;
        }
    }
    pause.show();
    pause.exec();
    stopbutton = 1;
    State tmp;
    tmp = UndoList[UndoList.size() - 1];
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            button[i][j]->setStyleSheet(tmp.style[i][j]);
            button[i][j]->setText(tmp.text[i][j]);
            numButton[i][j] = tmp.numButton[i][j];
            numEnabled[i][j] = tmp.numEnabled[i][j];
        }
    }
    record = tmp.record;
    UndoList.pop_back();
    timer->start();
}

void Game::on_Submit_clicked()
{
    if(stopbutton == 0)
        return ;
    check();
}

void Game::check()
{
    for(int i = 0; i < 9; i++)
    {
        std::set<int> ans;
        for(int j = 0; j < 9; j++)
        {
            if(numButton[i][j] != 1)
            {
                //TODO: format wrong
                std::cout<<"format"<<std::endl;
                return ;
            }
            for(int k = j + 1; k < 9; k++)
            {
                if(button[i][j]->text() == button[i][k]->text())
                {
                    //TODO:answer wrong
                    std::cout<<"lie answer"<<std::endl;
                    return ;
                }
                if(button[j][i]->text() == button[k][i]->text())
                {
                    //TODO:answer wrong
                    std::cout<<"hang answer"<<std::endl;
                    return ;
                }
            }
            for(int l = 0; l < 9; l++)
            {
                if(j/3 == i/3 && l/3 == i/3)
                {
                    ans.insert(button[j][l]->text().toInt());
                }
            }
        }
        if(ans.size() != 9)
        {
            //TODO: answer wrong
            std::cout<<"grid answer"<<std::endl;
            return ;
        }
    }
    std::cout<<"win"<<std::endl<<std::endl;
    timer->stop();
    Win w(timeRec->toString("mm:ss"));
    w.show();
    w.exec();
}

void Game::on_Undo_clicked()
{
    if(stopbutton == 0)
        return ;
    if(UndoList.size() == 0)
        return ;

    State pre;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            pre.style[i][j] = button[i][j]->styleSheet();
            pre.text[i][j] = button[i][j]->text();
            pre.numButton[i][j] = numButton[i][j];
            pre.numEnabled[i][j] = numEnabled[i][j];
        }
    }
    pre.record = record;

    State tmp;
    tmp = UndoList[UndoList.size() - 1];
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            button[i][j]->setStyleSheet(tmp.style[i][j]);
            button[i][j]->setText(tmp.text[i][j]);
            numButton[i][j] = tmp.numButton[i][j];
            numEnabled[i][j] = tmp.numEnabled[i][j];
        }
    }
    record = tmp.record;

    RedoList.push_back(pre);
    UndoList.pop_back();
    std::cout<<"UNDO:"<<std::endl<<"Undo:"<<UndoList.size()<<std::endl<<"Redo:"<<RedoList.size()<<std::endl;
}

void Game::on_Redo_clicked()
{
    if(stopbutton == 0)
        return ;
    if(RedoList.size() == 0)
        return ;
    State pre;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            pre.style[i][j] = button[i][j]->styleSheet();
            pre.text[i][j] = button[i][j]->text();
            pre.numButton[i][j] = numButton[i][j];
            pre.numEnabled[i][j] = numEnabled[i][j];
        }
    }
    pre.record = record;

    State tmp;
    tmp = RedoList[RedoList.size() - 1];
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            button[i][j]->setStyleSheet(tmp.style[i][j]);
            button[i][j]->setText(tmp.text[i][j]);
            numButton[i][j] = tmp.numButton[i][j];
            numEnabled[i][j] = tmp.numEnabled[i][j];
        }
    }
    record = tmp.record;
    std::cout<<"REDO:"<<std::endl<<"Undo:"<<UndoList.size()<<std::endl<<"Redo:"<<RedoList.size()<<std::endl;

    UndoList.push_back(pre);
    RedoList.pop_back();
}


void Game::on_Del_clicked()
{
    if(stopbutton == 0)
        return ;
    int x = record/10;
    int y = record%10;
    if(numEnabled[x][y] == 0)
        return ;
    addUndo();
    RedoList.clear();
    button[x][y]->setText("");
    numButton[x][y] = 0;
}

void Game::Hint_click()
{
    if(stopbutton == 0)
        return ;
    Solver sol;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            sol.data.data[i][j] = Level[levelSet][i][j];
        }
    }
    Data ans = sol.solve();
    addUndo();
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            button[i][j]->setText(QString::number(ans.data[i][j]));
            numButton[i][j] = 1;
        }
    }
    on_gridbutton_clicked(record);
    RedoList.clear();
}

void Game::addUndo()
{
    State tmp;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            tmp.style[i][j] = button[i][j]->styleSheet();
            tmp.text[i][j]  = button[i][j]->text();
            tmp.numButton[i][j] = numButton[i][j];
            tmp.numEnabled[i][j] = numEnabled[i][j];
//            tmp.numButtonUse= numButtonUse[9][9];
        }
    }
    tmp.record = record;
    UndoList.push_back(tmp);
}

void Game::Lab_click()
{
    int x = record / 10;
    int y = record % 10;
    addUndo();
    //button[x][y]->setAutoFillBackground(true);
    QPalette tmp;
    tmp.setBrush(QPalette::Background, QBrush(QPixmap(":/lab.png")));
    button[x][y]->setPalette(tmp);

    on_gridbutton_clicked(record);
}
