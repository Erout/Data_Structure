#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<iostream>
#include<string>
using std::string;
struct single{
    single* next;
    double coefficient;
    int exponent;
    single(double c,int e){
        coefficient = c;
        exponent = e;
        next = NULL;
    }
};
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    bool Input(string s,int id);
    void textToList();
    bool add();
    bool subtract();
    bool multiple();
    void derivative(int id);
    double valueOfX(double x,int id);
    string listToString(single* head);
    friend int stringToInt(string s);
    friend double stringToDouble(string s);
private slots:
	//加减乘求导带入值五个功能，其中，求导和带入值两个式子一起给出结果
	void on_addBtn_clicked();
    void on_subBtn_clicked();
    void on_mulBtn_clicked();
    void on_derBtn_clicked();
    void on_InpBtn_clicked();
    void on_show_clicked();

private:
    Ui::Widget *ui;
    single* first_head;
    single* second_head;
    single* result_head;
    bool addItem(string s,int id);
    bool addItemToFirst(double coe,int exp);
    bool addItemToSecond(double coe,int exp);
    bool addItemToThird(double coe,int exp);
    void clearResult();
    void clear();
    void sort();
    void sortTool(single* head);
    
};

#endif // WIDGET_H
