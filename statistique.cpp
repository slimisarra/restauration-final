#include "statistique.h"
#include "ui_statistique.h"
#include <QSqlQuery>
#include <QtCharts/QPieSlice>
#include<QPieSeries>

statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
    mainLayout=new QVBoxLayout;
    mainLayout->addWidget(S.Preparechart());
    ui->stat2->setLayout(mainLayout);
}

statistique::~statistique()
{
    delete ui;
}
