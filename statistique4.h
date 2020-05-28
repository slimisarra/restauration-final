#ifndef STATISTIQUE4_H
#define STATISTIQUE_H
#include <QVBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include "statistique5.h"
#include <QDialog>

namespace Ui {
class statistique4;
}

class statistique4 : public QDialog
{
    Q_OBJECT

public:
    explicit statistique4(QWidget *parent = nullptr);
    ~statistique4();

private:
    Ui::statistique4 *ui;
    QVBoxLayout * mainLayout;
    Statistique5 S ;
};

#endif // STATISTIQUE_H
