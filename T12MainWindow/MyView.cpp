#include "MyView.h"
#include <QPainter>
MyView::MyView(QWidget *parent) :
    QWidget(parent)
{
}


void MyView::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.fillRect(rect(), Qt::red);
}
