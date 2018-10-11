# 算法表达式求值演示

## 运行方式
    点开StackCal.exe可执行文件直接运行
    或在命令行中make之后，./StackCal运行

## 实现思路
    建立了一个StackCal的类，用字符串形式储存表达式，类中有一个操作数栈和一个操作符栈。
    private slots中的函数作用是往expression里面添加内容，记录单击输入的过程。
    eraseOne用于擦掉用户输入的最后一个字符。
    clear清空expression和栈的屏幕显示的内容.
    opNToString和opSToString用于协助输出两栈中剩余内容。
    compute计算表达式的值。
    friend函数用于辅助计算等。

    其中计算包括+ - * / ^ -- ++，以及括号操作，输入负数的时候需要用括号辅助。
    计算的时候，遇到数则入栈，遇到符号，判断优先级再决定是入栈还是运算还是出栈。
    另外有两个标志metSign（遇到加号或减号）和metLeft（遇到左括号）辅助判断负号和加加减减的情况。

    ui界面使用Qt实现，各控件的风格通过改变控件的stylesheet实现

## 程序运行情况

![](./1.jpg)
![](./2.jpg)
![](./3.jpg)
    