#include "hashtable.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hashTable w;
    w.constructSequence();
    w.show();

    return a.exec();
}
