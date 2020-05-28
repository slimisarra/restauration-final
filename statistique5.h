#ifndef STATISTIQUE5_H
#define STATISTIQUE5_H

#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

QT_CHARTS_USE_NAMESPACE

class Statistique5
{
    QChart *chart;
    QChartView *chartView;
public:
    Statistique5();
    QChartView *Preparechart();


};

#endif // STATISTIQUE5_H
