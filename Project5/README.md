# Project5 哈希表设计

## 思路
先将姓名转化成数字，再设计一个哈希函数将这些姓名对应到哈希表的索引。哈希表长为100。构造一个伪随机序列，出现冲突则通过这个伪随机序列再哈希找到新的空的索引，将姓名填进去。

## 主要函数解释
- constructSequence() 建立伪随机序列，并通过排序将它排成一个递增的序列
- setUpTable()通过读入文件的方式读入姓名，使用nameToInt函数将姓名转化为数字，数字mod77得到索引值，index = nameToInt(name)%77，若哈希表此位置为空，那么就填进去。否则通过再哈希法，newindex = (sequence[i]+index)%100在表中找到空的位置填进去
- printTable()打印哈希表
- searchTable(string name)在哈希表中查找一个姓名，找到则返回索引，找不到返回-1。查找和建立哈希表的函数是一样的.
- printSearchLen()输出搜索的长度
- nameToInt()将姓名转化成数字
- quickSort()快速排序
- partition()快速排序的partition

## 运行方式
在name.in文件中输入姓名，一行一个，是英文姓名。
命令行可make之后运行a.out文件
qt界面版点击读入文件建立哈希表之后，就可以在搜索框中进行搜索了。
