#include "piechartwidget.h"
#include "produit.h"

#include <QPainter>

piechartwidget::piechartwidget(QWidget *parent) : QWidget(parent)
{

}

void piechartwidget::paintEvent(QPaintEvent *)
{
        produit tmpp;
        QPainter painter(this);
        QRectF size = QRectF(5,5, this->width()-10,this->width()-10);

        int moins = tmpp.stat_moins();
        moins= ((moins * 360) / 100);
        painter.setBrush(Qt::red);
        painter.drawPie(size, 0, (moins*16));

        int plus = tmpp.stat_plus();
        plus= ((plus * 360) / 100);
        painter.setBrush(Qt::green);
        painter.drawPie(size, ((360-plus)*16),(plus*16));

}
