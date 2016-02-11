#include <qlcdnumber.h>
#include <qslider.h>

#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent, char *name) : QVBox(parent, name) {
    QLCDNumber *lcd = new QLCDNumber(this);
    QSlider *s = new QSlider(QSlider::Horisontal, this);

    connect(s, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
}
