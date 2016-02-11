#include <qapplication.h>

#include "mywidget.h"

int main(int argc, char **argv) {
    QApplication a(argc, argv);

    MyWidget *w = new MyWidget();
    a.setMainWidget(w);
    w->show();

    return a.exec();
}
