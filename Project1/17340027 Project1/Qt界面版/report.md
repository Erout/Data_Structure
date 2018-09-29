# Qt界面版一元多项式计算器
## 运行方式
    打开codes文件夹，进入release文件夹，找到polyCal.exe即可运行，或者点击此文件夹下的polyCal快捷方式运行

## 实现思路
    建立了一个窗口类WIdget，里面设立了各种按钮和显示和输入的文本框
    类里面的一些槽函数：

- on_addBtn_clicked()：进行加法
- on_subBtn_clicked()：进行减法
- on_mulBtn_clicked()：进行乘法
- on_derBtn_clicked()：求导
- on_InpBtn_clicked()：输入x值并代入得到结果

  类里面同样是用三个链表分别储存两个多项式和结果的值，Input(),sort(),clean()等函数和命令行里面的一样

## 程序运行情况
![](./q1.jpg)
![](./q2.jpg)
![](./q3.jpg)
![](./q4.jpg)

## 样例格式化输入
1. 2x +5x^8 -3.1x^11  和 7 -5x^8 +11x^9
2. 6x^-3 -x +4.4x^2 -1.2x^9 和 -6x^-3 +5.4x^2 -x^2 +7.8x^15
3. 1 +x +x^2 +x^3 +x^4 +x^5 +x^6 和 -x^3 -x^4
4. x +x^3  和 -x -x^3
5. x +x^100  和 x^100 +x^200
6. x +x^2 +x^3 和 0