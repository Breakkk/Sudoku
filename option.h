#ifndef OPTION_H
#define OPTION_H

#include <QDialog>

namespace Ui {
class Option;
}

class Option : public QDialog
{
    Q_OBJECT

public:
    explicit Option(QWidget *parent = 0);
    int on_off = 0;
    ~Option();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Option *ui;
};

#endif // OPTION_H
