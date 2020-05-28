#ifndef STATISTIQUE3_H
#define STATISTIQUE3_H

#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

QT_CHARTS_USE_NAMESPACE

class Statistique3
{
    QChart *chart;
    QChartView *chartView;
public:
    Statistique3();
    QChartView *Preparechart();


};

#endif // STATISTIQUE3_H
