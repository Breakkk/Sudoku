#ifndef WIN_H
#define WIN_H

#include <QDialog>
#include <QString>

namespace Ui {
class Win;
}

class Win : public QDialog
{
    Q_OBJECT

public:
    explicit Win(QString, QWidget *parent = 0);
    ~Win();

private slots:
    void on_back_clicked();

private:
    Ui::Win *ui;
};

#endif // WIN_H
