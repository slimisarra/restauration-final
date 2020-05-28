#ifndef STATISTIQUE1_H
#define STATISTIQUE1_H
#include <QVBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QDialog>
#include "statistique3.h"
namespace Ui {
class statistique1;
}

class statistique1 : public QDialog
{
    Q_OBJECT

public:
    explicit statistique1(QWidget *parent = nullptr);
    ~statistique1();

private:
    Ui::statistique1 *ui;
    QVBoxLayout * mainLayout;
    Statistique3 S ;
};

#endif // STATISTIQUE_H
