//main.cpp

#include <QtWidgets/QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login win;
    win.show();

    return a.exec();
}
