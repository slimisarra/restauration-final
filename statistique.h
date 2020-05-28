#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include <QVBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include "statistique2.h"
#include <QDialog>

namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();

private:
    Ui::statistique *ui;
    QVBoxLayout * mainLayout;
    Statistique2 S ;
};

#endif // STATISTIQUE_H
