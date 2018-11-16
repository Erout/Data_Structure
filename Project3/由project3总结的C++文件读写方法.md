# 根据project3总结出的C++一些实用读写技巧
以备日后不时之需，特写此文，以免以后产生被自己坑了的感受。
## 一个个读取字符直到文件尾

```C++
ifstream fin;
fin.open("fileName");
char c;
while((c = fin.get()) != EOF){
    cout<<c;
}
```
此方法不仅可以读取空格，还可以读取换行

## 读取特定的数据类型
比如一行行读取表格的内容。可以将表格的一行内容分解为几种不同的数据类型，比如string double int这样，它们之间有空格分隔，可以这样进行读取
```C++
ifstream fin;
fin.open("fileName");
string s;
double d;
int i;
char c;
/*method 1*/
while(!fin.eof()){
    fin>>s;
    fin>>d;
    fin>>i;
}
/*method 2*/
while(!fin.eof()){
    fin>>s>>c>>d>>c>>i;
}
