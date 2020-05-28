#include "statistique1.h"
#include "ui_statistique1.h"
#include <QSqlQuery>
#include <QtCharts/QPieSlice>
#include<QPieSeries>
#include <QVBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
statistique1::statistique1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique1)
{
    ui->setupUi(this);
    setWindowTitle("STATISTIQUE");
    mainLayout=new QVBoxLayout;
    mainLayout->addWidget(S.Preparechart());
    ui->stat2->setLayout(mainLayout);
}

statistique1::~statistique1()
{
    delete ui;
}
