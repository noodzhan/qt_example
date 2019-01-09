#include "MyWidget.h"
#include <QPainter>
#include <QPixmap>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
}

void MyWidget::paintEvent(QPaintEvent *)
{
    //像素投影
    QPixmap pixmap(size());

    QPainter p(&pixmap);

 //   p.translate(100, 100);
    //p.scale();
    p.setRenderHint(QPainter::Antialiasing);//圆滑处理
    QTransform transform;
    transform.translate(50,50); //旋转原点
    transform.rotate(30);  //旋转30度
   // transform.scale(.5, .5); //整体缩放
    p.setTransform(transform);
#if 1
    QTransform transform2;
    transform2.scale(.5, .5);
    p.setTransform(transform2, true);
#endif

    p.drawLine(QPoint(0, 0), QPoint(100, 100));

 //   p.translate(-100, -100);
    p.setPen(QPen(Qt::red, 2, Qt::DashLine));//影响文字的颜色

    //填充
    p.setBrush(Qt::yellow);//影响封闭图形的颜色
   //设置字体
    p.setFont(QFont("aaa", 40, 700, true));
    //画椭圆
    p.drawEllipse(QPoint(95, 333), 50, 50);
    //画文字
    p.drawText(QPoint(300, 50), "Hello world");
 //   p.drawPixmap(QPoint(40, 40), QPixmap("../aaa.png"));
  //  p.drawRect(QRect(40, 60, 100, 50));

    //画矩形
    p.drawRoundRect(QRect(40, 60, 100, 50));

    p.end();

    p.begin(this);

    //设置坐标原点
    p.drawPixmap(0, 0, pixmap);

}

void MyWidget::mousePressEvent(QMouseEvent *)
{
    QPixmap pixmap(size());
    QPainter painter(&pixmap);
    render(&painter);
    pixmap.save("../Painter.png");
}

#include <QApplication>
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MyWidget w;
    w.show();

    return app.exec();
}
