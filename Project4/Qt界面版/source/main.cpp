#include "graph.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    graph w;
    w.setUpGraph();
    w.show();

    return a.exec();
}
