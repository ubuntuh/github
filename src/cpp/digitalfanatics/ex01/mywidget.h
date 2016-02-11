#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <qvbox.h>

class MyWidget : public QVBox
{
    Q_OBJECT

 public:
    MyWidget(QWidget *parent = 0, char *name = 0);
};

#endif
