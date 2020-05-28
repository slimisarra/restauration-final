#include "statistique4.h"
#include "ui_statistique4.h"
#include <QSqlQuery>
#include <QtCharts/QPieSlice>
#include<QPieSeries>

statistique4::statistique4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique4)
{
    ui->setupUi(this);
    mainLayout=new QVBoxLayout;
    mainLayout->addWidget(S.Preparechart());
    ui->stat2->setLayout(mainLayout);
}

statistique4::~statistique4()
{
    delete ui;
}
