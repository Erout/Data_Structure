# 命令行版一元多项式计算器
## 运行方式
    文件夹中有Makefile
    make之后./Calculator即可运行
## 实现思路
    建立了一个Calculator的类，里面有三个链表，分别储存输入的两个多项式和结果。
    fist_head存的是第一个多项式的头节点，second_head存的是第二个多项式的头节点，result_head存的是结果的头节点。
    Calculator的类中有各类方法实现其功能：
- Input(string s,int id):把多项式字符串输入到第一或者第二个多项式里面 addItem(),addItemToFirst(),addItemToSecond()，stringToInt(),strinigToDouble()是辅助Input()的函数
- add()：两式相加
- subtract()：两式相减
- multiple()：两式相乘
- derivative()：求导
- valueOfX():代入x值
- showResult():显示结果
- display():打印输入的多项式
- sort():进行降幂排序
- clear(),clearResult():清除

## 程序运行情况
![](./1.jpg)
![](./2.jpg)


## 样例格式化输入
1. 2x +5x^8 -3.1x^11  和 7 -5x^8 +11x^9
2. 6x^-3 -x +4.4x^2 -1.2x^9 和 -6x^-3 +5.4x^2 -x^2 +7.8x^15
3. 1 +x +x^2 +x^3 +x^4 +x^5 +x^6 和 -x^3 -x^4
4. x +x^3  和 -x -x^3
5. x +x^100  和 x^100 +x^200
6. x +x^2 +x^3 和 0