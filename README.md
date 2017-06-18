## 啊哈！算法相关的代码示例 ##
《啊哈！算法》，作者的[官方网站](http://www.ahalei.com/)，如果没有买书，可以查看：
- 作者的[CSDN](http://blog.csdn.net/ahalei)
- 作者的[博客园](http://www.cnblogs.com/ahalei/)

### 相关说明 ###
- .c文件为C语言文件，Windows下可以通过Cygwin运行gcc编译成exe文件，也可以用vagrant加载linux虚拟机来运行，相关命令：
```
//windows下
gcc quick_sort.c -o quick_sort
./quick_sort.exe
//linux下
gcc quick_sort.c -o quick_sort.out
./quick_sort.out
```
- .php文件为用php写的相关算法，同样在命令行下运行
```
php quick_sort.php
```

### 当前进度 ###
- 1_sort 为第一章：排序相关算法
    - bucket_sort 桶排序，其中php文件中顺便增加了同时展示姓名和分数的方法
    - bubble_sort 冒泡排序，其中php文件中也顺便实现了选择排序和插入排序
    - quick_sort  快速排序
- 2_list 为第二章：栈、队列、链表
    - queue 队列
    - stack 栈