#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    first_head =nullptr;
    second_head=nullptr;
    result_head=nullptr;
}

Widget::~Widget()
{
    delete ui;
    first_head =nullptr;
    second_head=nullptr;
    result_head=nullptr;
}
int stringToInt(string s){
    int total = 0;
    int sign;
    string ns;
    if(s[0] == '-'){
        sign = 1;
        ns = s.substr(1,s.size()-1);
    }
    else if(s[0] == '+'){
        sign = 0;
        ns = s.substr(1,s.size()-1);
    }
    else{
        sign = 0;
        ns = s;
    }
    for(int i = 0; i < ns.size(); i++){
        total += (ns[i]-'0')*pow(10,ns.size()-i-1);
    }
    if(sign == 0)
        return total;
    else
        return -total;
}
double stringToDouble(string s){
    double total = 0;
    int sign;
    string ns;
    if(s[0] =='-'){
        sign = 1;
        ns = s.substr(1,s.size()-1);
    }
    else if(s[0] == '+'){
        sign = 0;
        ns = s.substr(1,s.size()-1);
    }
    else{
        sign = 0;
        ns = s;
    }
    int pointP = -1;
    for(int i = 0; i < ns.size();i++){
        if(ns[i] =='.')
            pointP = i;
    }
    total += stringToInt(ns.substr(0,pointP));
    int cal = -1;
    if(pointP != -1){
        for(int i = pointP+1; i < ns.size(); i++){
            total += (ns[i]-'0')*pow(10,cal);
            cal--;
        }
    }
    if(sign == 0)
        return total;
    else
        return -total;
}
void Widget::clearResult(){
    single* temp = result_head;
    while(temp != nullptr){
        result_head = result_head->next;
        delete temp;
        temp = result_head;
    }
    result_head = nullptr;
}
void Widget::clear(){
    clearResult();
    single* temp = first_head;
    while(temp != nullptr){
        first_head = first_head->next;
        delete temp;
        temp = first_head;
    }
    single* temp2 = second_head;
    while(temp2 != nullptr){
        second_head = second_head->next;
        delete temp2;
        temp2 = second_head;
    }
    first_head = second_head = nullptr;
}
bool Widget::Input(string s, int id){
    s += ' ';
    string temp;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            addItem(temp,id);
            temp.clear();
        }
        else{
            temp += s[i];
        }
    }
    return true;
}
//单项
bool Widget::addItem(string s, int id){
    if(s.size() == 0)
        return false;
    int xPosition = -1;
    int expPosition = -1;
    double coe;
    int exp;
    for(int i = 0; i < s.size();i++){
        if(s[i] == 'x')
            xPosition = i;
        if(s[i] == '^')
            expPosition = i;
    }
    if(xPosition == -1){
        exp = 0;
        coe = stringToDouble(s);
    }
    else if(xPosition == 0){
        coe = 1;
        if(expPosition == -1)
            exp = 1;
        else
            exp = stringToInt(s.substr(expPosition+1,s.size()-expPosition-1));
    }
    else if((xPosition == 1)&&(s[0] == '-')){
        coe = -1;
        if(expPosition == -1)
            exp = 1;
        else
            exp = stringToInt(s.substr(expPosition+1,s.size()-expPosition-1));
    }
    else if((xPosition == 1)&&(s[0] == '+')){
        coe = 1;
        if(expPosition == -1)
            exp = 1;
        else
            exp = stringToInt(s.substr(expPosition+1,s.size()-expPosition-1));
    }
    else{
        if(expPosition == -1){
            exp = 1;
            coe = stringToDouble(s.substr(0,xPosition));
        }
        else{
            exp = stringToInt(s.substr(expPosition+1,s.size()-expPosition-1));
            coe = stringToDouble(s.substr(0,xPosition));
        }
    }
    if((coe == 0)&&(exp == 0))
        return false;
    if(id == 1)
        addItemToFirst(coe,exp);
    else if(id == 2)
        addItemToSecond(coe,exp);
    else if(id == 3)
        addItemToThird(coe,exp);
    return true;
}
bool Widget::addItemToThird(double coe,int exp){
    if(coe == 0)
        return false;
    single* temp = result_head;
    bool existence = 0;
    if(result_head == nullptr)
        result_head = new single(coe,exp);
    else{
        while(temp->next != nullptr){
            if(temp->exponent == exp){
                existence = 1;
                break;
            }
            temp = temp->next;
        }
        if(temp->exponent == exp){
            existence = 1;
        }
        if(existence == 1)
            temp->coefficient += coe;
        else
            temp->next = new single(coe,exp);
    }
    return true;
}
bool Widget::addItemToFirst(double coe,int exp){
    single* temp = first_head;
    bool existence = 0;
    if(first_head == nullptr)
        first_head  = new single(coe,exp);
    else{
        while(temp->next != nullptr){
            if(temp->exponent ==exp){
                existence = 1;
                break;
            }
            temp = temp->next;
        }
        if(temp->exponent == exp){
            existence = 1;
        }
        if(existence == 1){
            temp->coefficient += coe;
        }
        else
            temp->next = new single(coe,exp);
    }
    return true;
}
bool Widget::addItemToSecond(double coe,int exp){
    single* temp = second_head;
    bool existence = 0;
    if(second_head == nullptr)
        second_head = new single(coe,exp);
    else{
        while(temp->next != nullptr){
            if(temp->exponent == exp){
                existence = 1;
                break;
            }
            temp = temp->next;
        }
        if(temp->exponent == exp){
            existence = 1;
        }
        if(existence == 1){
            temp->coefficient += coe;
        }
        else
            temp->next = new single(coe,exp);
    }
    return true;
}
bool Widget::add(){
    //string s,total;
    clearResult();
    single* temp1 = first_head;
    single* temp2 = second_head;
    while(temp1 != nullptr){
        addItemToThird(temp1->coefficient,temp1->exponent);
        temp1 = temp1->next;
    }
    while(temp2 != nullptr){
        addItemToThird(temp2->coefficient,temp2->exponent);
        temp2 = temp2->next;
    }
    return true;
}
void Widget::sort(){
    sortTool(first_head);
    sortTool(second_head);
    sortTool(result_head);
}
void Widget::sortTool(single* head){
    single* r = head;
    single* r1 = r;
    int tempcoe,tempexp;
    for(r; r != nullptr; r = r->next){
        for(r1 = r; r1 != nullptr; r1 = r1->next){
            if(r->exponent <r1->exponent){
                tempcoe = r->coefficient;
                tempexp = r->exponent;
                r->coefficient = r1->coefficient;
                r->exponent = r1->exponent;
                r1->coefficient = tempcoe;
                r1->exponent = tempexp;
            }
        }
    }
}
string Widget::listToString(single* head){
    sort();
    single* temp = head;
    bool firstItemAppear = 0;
    string s;
    char* c = new char[500];
    while(temp != nullptr){
        if(temp->coefficient == 0){
            if((temp->next != NULL)&&(temp->next->coefficient > 0)&&(firstItemAppear)){
                //cout<<"+";
                sprintf(c,"%c",'+');
                s += c;
            }
            temp = temp->next;
            continue;
        }
        if(temp->exponent == 0){
            sprintf(c,"%.2lf",temp->coefficient);
            s += c;
            firstItemAppear = 1;
        }
        else if(temp->exponent == 1){
            if(temp->coefficient == 1){
                sprintf(c,"%c",'x');
                s += c;
            }
            else if(temp->coefficient == -1){
                sprintf(c,"%c%c",'-','x');
                s += c;
            }
            else{
                sprintf(c,"%.2lf%c",temp->coefficient,'x');
                s += c;
            }
            firstItemAppear = 1;
        }
        else{
            if(temp->coefficient == 1){
                sprintf(c,"%c%c%d",'x','^',temp->exponent);
                s += c;
            }

            else if(temp->coefficient == -1){
                sprintf(c,"%c%c%c%d",'-','x','^',temp->exponent);
                s += c;
            }
            else{
                sprintf(c,"%.2lf%c%c%d",temp->coefficient,'x','^',temp->exponent);
                s += c;
            }
            firstItemAppear = 1;
        }
        if((temp->next != nullptr)&&(temp->next->coefficient > 0)){
            s += '+';
        }
        temp = temp->next;
    }
    if(!firstItemAppear){
        s += '0';
    }
    return s;
}
bool Widget::subtract(){
    clearResult();
    single* temp1 = first_head;
    single* temp2 = second_head;
    while(temp1 != nullptr){
        addItemToThird(temp1->coefficient,temp1->exponent);
        temp1 = temp1->next;
    }
    while(temp2 != nullptr){
        addItemToThird(-temp2->coefficient,temp2->exponent);
        temp2 = temp2->next;
    }
}
bool Widget::multiple(){
    //系数相乘，指数相加 
    clearResult();
    single* p = first_head;
    single* q = second_head;
    while(p != nullptr){
        q = second_head;
        while(q != nullptr){
            addItemToThird(p->coefficient*q->coefficient,p->exponent+q->exponent);
            q = q->next;
        } 
        p = p->next;
    }
}
void Widget::derivative(int id){
    clearResult();
    single* temp1 = first_head;
    single* temp2 = second_head;
    if(id == 1){
        while(temp1 != nullptr){
            addItemToThird(temp1->coefficient*temp1->exponent,temp1->exponent-1);
            temp1 = temp1->next;
        }
    }
    else if(id == 2){
        while(temp2 != nullptr){
            addItemToThird(temp2->coefficient*temp2->exponent,temp2->exponent-1);
            temp2 = temp2->next;
        }
    }
}
double Widget::valueOfX(double x,int id){
    double result = 0;
    single* temp;
    if(id == 1){
        temp = first_head;
    }
    else if(id == 2){
        temp = second_head;
    }
    else{
        return 0;
    }
    while(temp != nullptr){
        result += temp->coefficient*pow(x,temp->exponent);
        temp = temp->next;
    }
    return result;
    //cout<<"result1: "<<result1<<endl<<"result2: "<<result2<<endl;
}
void Widget::textToList(){
    QString qs1 = ui->poly1->text();
    QString qs2 = ui->poly2->text();
    string s1 = qs1.toStdString();
    string s2 = qs2.toStdString();
    clear();
    Input(s1,1);
    Input(s2,2);
}
void Widget::on_addBtn_clicked(){
    textToList();
    add();
    string s3 = listToString(result_head);
    QString qs3 = QString::fromStdString(s3);
    ui->cal1->setText(qs3);
}
void Widget::on_subBtn_clicked(){
    textToList();
    subtract();
    string s3 = listToString(result_head);
    QString qs3 = QString::fromStdString(s3);
    ui->cal1->setText(qs3);
}
void Widget::on_mulBtn_clicked(){
    textToList();
    multiple();
    string s3 = listToString(result_head);
    QString qs3 = QString::fromStdString(s3);
    ui->cal1->setText(qs3);
}
void Widget::on_derBtn_clicked(){
    textToList();
    derivative(1);
    string s1 = listToString(result_head);
    QString qs1 = QString::fromStdString(s1);
    ui->rst1->setText(qs1);
    derivative(2);
    string s2 = listToString(result_head);
    QString qs2 = QString::fromStdString(s2);
    ui->rst2->setText(qs2);
}
void Widget::on_InpBtn_clicked(){
    textToList();
    double x = ui->XSpinBox->value();
    QString qs1 = QString::number(valueOfX(x,1));
    ui->rst1->setText(qs1);
    QString qs2 = QString::number(valueOfX(x,2));
    ui->rst2->setText(qs2);
}
void Widget::on_show_clicked(){
    textToList();
    sort();
    string s1 = listToString(first_head);
    string s2 = listToString(second_head);
    QString qs1 = QString::fromStdString(s1);
    QString qs2 = QString::fromStdString(s2);
    ui->rst1->setText(qs1);
    ui->rst2->setText(qs2);
}
