#include "statistique3.h"
#include <QSqlQuery>
#include <QtCharts/QPieSlice>
#include<QPieSeries>
#include "produit.h"

QT_CHARTS_USE_NAMESPACE

Statistique3::Statistique3(){

}

QChartView *Statistique3::Preparechart(){
         produit p;
         QPieSeries *series;
         series = new QPieSeries();
         int moins = p.stat_moins();
           moins= ((moins * 360) / 100);
             series->append("Qt inferieur à 10 ", (moins*16));

             int plus = p.stat_plus();
               plus= ((plus * 360) / 100);
             series->append("Qt superieur à 10",(plus*16));

    QPieSlice *slice = series->slices().at(1);

       series->setLabelsVisible();
   //  slice->setExploded();

       slice->setPen(QPen(Qt::red, 1));
       slice->setBrush(Qt::blue);

       chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("**    Articles en rupture de stock    **");
       chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       return chartView;
}
