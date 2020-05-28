#ifndef PROG_H
#define PROG_H

#include <QDialog>

namespace Ui {
class prog;
}

class prog : public QDialog
{
    Q_OBJECT

public:
    explicit prog(QWidget *parent = nullptr);
    ~prog();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::prog *ui;
};

#endif // PROG_H
