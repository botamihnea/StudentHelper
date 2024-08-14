#include "A89.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>
#include <qboxlayout.h>
#include "tests.h"
#include "ui.h"
#include <iostream>
#include "gui.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget mainWidget;
    mainWidget.show();
    return a.exec();
}
