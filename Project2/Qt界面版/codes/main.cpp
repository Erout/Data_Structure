#include "stackcal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StackCal w;
    w.show();

    return a.exec();
}
