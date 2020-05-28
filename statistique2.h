#ifndef STATISTIQUE2_H
#define STATISTIQUE2_H

#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

QT_CHARTS_USE_NAMESPACE

class Statistique2
{
    QChart *chart;
    QChartView *chartView;
public:
    Statistique2();
    QChartView *Preparechart();


};

#endif // STATISTIQUE2_H
