#include "hashtable.h"
#include "ui_hashtable.h"
#define HkeyMod 77
#define indexMod 100
hashTable::hashTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hashTable)
{
    ui->setupUi(this);
    for(int i = 0; i < SIZE-1; i++)
        sequence[i] = 0;
    searchLen = 0;
    model = new QStandardItemModel();
    model->setColumnCount(5);
    model->setHeaderData(0,Qt::Horizontal,QString::fromStdString("Index"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromStdString("Name"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromStdString(" "));
    model->setHeaderData(3,Qt::Horizontal,QString::fromStdString("Index"));
    model->setHeaderData(4,Qt::Horizontal,QString::fromStdString("Name"));
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,80);
    ui->tableView->setColumnWidth(1,150);
    ui->tableView->setColumnWidth(2,100);
    ui->tableView->setColumnWidth(3,80);
    ui->tableView->setColumnWidth(4,150);
    ui->tableView->verticalHeader()->hide();
}

hashTable::~hashTable()
{
    delete ui;
}
void hashTable::constructSequence(){
    int order = 0;
    while(order != SIZE-1){
        sequence[order++] = rand()%50;
    }
    quickSort(0,SIZE-2,sequence);
}
void hashTable::setUpTable(){
    ifstream fin("name.in");
    string s;
    int Hkey,index,order;
    while(!fin.eof()){
        fin>>s;
        Hkey = nameToInt(s) % HkeyMod;
        if(Table[Hkey].size() == 0){
            Table[Hkey] = s;
            searchLen++;
        }
        else{
            order = 0;
            index = (sequence[order++]+Hkey) % indexMod;
            searchLen++;
            while(Table[index].size() != 0){
                index = (sequence[order++]+Hkey) % indexMod;
                searchLen++;
            }
            Table[index] = s;
        }
    }
    showTable();
    ui->avgLen->setText(QString::number(searchLen/30));
}
void hashTable::showTable(){
    model->clear();
    model->setColumnCount(5);
    model->setHeaderData(0,Qt::Horizontal,QString::fromStdString("Index"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromStdString("Name"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromStdString(" "));
    model->setHeaderData(3,Qt::Horizontal,QString::fromStdString("Index"));
    model->setHeaderData(4,Qt::Horizontal,QString::fromStdString("Name"));
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,80);
    ui->tableView->setColumnWidth(1,150);
    ui->tableView->setColumnWidth(2,100);
    ui->tableView->setColumnWidth(3,80);
    ui->tableView->setColumnWidth(4,150);
    ui->tableView->verticalHeader()->hide();
    int row = 0;
    int side = 0;
    for(int i = 0; i < SIZE; i++){
        if(Table[i].size()){
            if(side%2 == 0){
                model->setItem(row,0,new QStandardItem(QString::number(i)));
                model->setItem(row,1,new QStandardItem(QString::fromStdString(Table[i])));
            }
            else{
                model->setItem(row,3,new QStandardItem(QString::number(i)));
                model->setItem(row,4,new QStandardItem(QString::fromStdString(Table[i])));
                row++;
            }
            side++;
        }

    }
}
int hashTable::searchTable(string s){
    int Hkey,index,order;
    Hkey = nameToInt(s) % HkeyMod;
    if(Table[Hkey] == s){
        return Hkey;
    }
    else{
        order = 0;
        index = (sequence[order++]+Hkey) % indexMod;
        searchLen++;
        while(Table[index] != s && order < SIZE-1){
            index = (sequence[order++]+Hkey) % indexMod;
        }
        if(order == SIZE-1) return -1;
        else return index;
    }
}
void hashTable::printSearchLen(){}
void hashTable::on_pushButton_clicked(){
    QString name;
    name = ui->lineEdit->text();
    int index;
    index = searchTable(name.toStdString());
    ui->nameindex->setText(QString::number(index));
}
void hashTable::on_file_clicked(){
    setUpTable();
}
long long hashTable::nameToInt(string name){
    unsigned int len = name.size();
    int exp = 1;
    int ans = 0;
    for(int i = (int)len-1; i >= 0; i--){
        ans += name[i]*exp;
        exp *= 2;
    }
    return ans;
}
void hashTable::quickSort(int low, int high, int array[]){
    int pivot;
    if(low < high){
        pivot = partition(low,high,array);
        quickSort(low,pivot-1,array);
        quickSort(pivot+1,high,array);
    }
}
int hashTable::partition(int low, int high, int array[]){
    int key = array[low];
    while(low < high && array[high] >= array[low])
        high--;
    array[low] = array[high];
    while(low < high && array[low] <= array[high])
        low++;
    array[high] = array[low];
    array[low] = key;
    return low;
}
