#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QMainWindow>
#include<QStandardItemModel>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#define SIZE 100
using std::ifstream;
using std::string;
namespace Ui {
class hashTable;
}

class hashTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit hashTable(QWidget *parent = nullptr);
    ~hashTable();
    void constructSequence();
    void setUpTable();
    void showTable();
    int searchTable(string s);
    void printSearchLen();
private slots:
    void on_pushButton_clicked();
    void on_file_clicked();
private:
    Ui::hashTable *ui;
    string Table[SIZE];
    int searchLen;
    int sequence[SIZE-1];
    QStandardItemModel* model;
    long long nameToInt(string name);
    void quickSort(int low, int high, int array[]);
    int partition(int low, int high, int array[]);

};

#endif // HASHTABLE_H
