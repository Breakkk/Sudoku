#ifndef PAUSE_H
#define PAUSE_H

#include <QDialog>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class Pause;
}

class Pause : public QDialog
{
    Q_OBJECT

public:
    explicit Pause(QWidget *parent = 0);
    ~Pause();

private slots:
    void on_continue_2_clicked();

private:
    Ui::Pause *ui;
};

#endif // PAUSE_H
