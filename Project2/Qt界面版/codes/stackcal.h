#ifndef STACKCAL_H
#define STACKCAL_H

#include <QWidget>
#include<iostream>
#include<stack>
#include<string>
#include<QStandardItemModel>
using std::string;
using std::stack;
using std::cin;
using std::cout;
using std::endl;
namespace Ui {
class StackCal;
}

class StackCal : public QWidget
{
    Q_OBJECT

public:
    explicit StackCal(QWidget *parent = nullptr);
    ~StackCal();
    void Input(string s);
    void eraseOne();
    void clear();
    string opNToString();
    string opSToString();
    bool compute();
    void uiColor();
    friend int stringToInt(string s);
    friend bool isNumber(char c);
    friend bool equalTo(char a,char b);
    friend bool smallerThan(char a,char b);
    friend int calculate(int front,int back, char operate);
private slots:
    void on_one_clicked();
    void on_two_clicked();
    void on_three_clicked();
    void on_four_clicked();
    void on_five_clicked();
    void on_six_clicked();
    void on_seven_clicked();
    void on_eight_clicked();
    void on_nine_clicked();
    void on_zero_clicked();
    void on_add_clicked();
    void on_sub_clicked();
    void on_mul_clicked();
    void on_exc_clicked();
    void on_exp_clicked();
    void on_leftKuo_clicked();
    void on_rightKuo_clicked();
    void on_equal_clicked();
    void on_clear_clicked();
    void on_erase_clicked();
private:
    Ui::StackCal *ui;
    QStandardItemModel* model ;
    string expression;//存储表达式
    stack<int> opNum;//储存操作数
    stack<char> opSign;//储存运算符
    int opN[100];//操作数栈中的内容，用来显示输出
    char opS[100];//操作符栈的内容，用来显示输出
    int NFlag;//opN的标志
    int SFlag;//opS的标志
};

#endif // STACKCAL_H
