#include "statistique2.h"
#include <QSqlQuery>
#include <QtCharts/QPieSlice>
#include<QPieSeries>
#include "vendre.h"

QT_CHARTS_USE_NAMESPACE

Statistique2::Statistique2(){

}

QChartView *Statistique2::Preparechart(){
         vendre v;
         QPieSeries *series;
         series = new QPieSeries();
         int moins = v.stat_moins();
           moins= ((moins * 360) / 100);
             series->append("prix inferieur à 100 ", (moins*16));

             int plus = v.stat_plus();
               plus= ((plus * 360) / 100);
             series->append("prix superieur à 100",(plus*16));

    QPieSlice *slice = series->slices().at(1);

       series->setLabelsVisible();
   //  slice->setExploded();

       slice->setPen(QPen(Qt::red, 1));
       slice->setBrush(Qt::blue);

       chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("** Statistique Prix des Equipements à vendre **");
       chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       return chartView;
}
