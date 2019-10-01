# leetcode

| ID | problem | 难度 | 使用语言 | 思路 | 提交次数 | WA点 | star |
| :---:  | :---: | :---: | :---:  | :---: | :---: | :---: | :---: |
| 1 | 两数之和 | 简单 | C++ | | | | |
| 2 | 两数相加 | 中等 | Java | | | | |
| 3 | 无重复字符的最长子串  | 中等 | Java | | | | |
| 5 | 最长回文子串 | 中等 | python | | | | |
| 7 | 整数反转 | 简单 | python | | | | |
| 8 | 字符串转换整数(atoi) | 中等 | C++ | | | | |
| 11 | 盛最多水的容器 | 中等 | C++ | 双指针法 | | | :star: |
| 15 | 三数之和 | 中等 | C++ | | | | |
| 17 | 电话号码的字母组合 | 中等 | C++ | | | | |
| 19 | 删除链表的倒数第N个节点  | 中等 | C++ | | | | |
| 20 | 有效的括号 | 简单 | C++ | | | | |
| 21 | 合并两个有序链表 | 简单 | C++ | | | | |
| 22 | 括号生成 | 中等 | C++ | | | | |
| 28 | 实现strStr() | 简单 | C++ | | | | |
| 29 | 两数相除（不使用乘法除法） | 中等 |  Java | 用被除数不断减去除数直至被减数为负（TLE），每次将减数翻倍 | 8 | 边界 | :star: |
| 33 | 搜索旋转排序数组 | 中等 | Java | | | | |
| 34 | 在排序数组中查找元素的第一个和最后一个位置 | 中等 | Java | 两次二分查找，先找左边界，再找右边界 | 1 | \ |  |
| 36 | 有效的数独 | 中等 | Java | 暴力，对所有行、所有列、所有九宫格分别检测(扫描243次)<br>优解：所有格子只遍历一次，根据`i`，`j`得出对应`row`、`column`、`block`的值，并判断这个值在上述三项的`Hashmap`中是否出现过(扫描81次) | 1 | \ |  |
| 46 | 全排列 | 中等 | Java | ~~用C++的`next_permutation`秒杀~~将已排列的部分递增，未排列的部分递减，递归即可。<br>优解：实现时，不必每次都传入新的已排列`List`和未排列`List`，只需要用`index`标记已排列和未排列区域的分界即可，使用`swap`将未排列区域的值交换到已排列区域，全程只需要一个`List`。 | 1 | \ | |
| 48 | 旋转图像 | 中等 | Java | 四条边上依次取一个对应位置进行顺序交换，只需O(1)存储空间存储第一个值，三变量交换的扩展<br>优解：将矩阵转置后左右对称交换，复杂度均为O(N^2)但思路与实现都更简单 | 2 | 下标表达式写错 | |
| 49 | 字母异位词分组 | 中等 | Java | 维护一个`Hashmap<String, List>`，以排序后的String作为key，将未排序的key加入value的List即可。对熟悉Hashmap基本操作很有帮助。 | 1 | \ | |
| 50 | Pow(x, n) | 中等 | Java | 快速幂 | 3 | 快速幂写错，边界值`Integer.MIN_VALUE`的处理（直接用`long`就好了嘛用什么int） | |
| 53 | 最大子序和 | 简单 | C++ | | | | |
| 56 | 合并区间 | 中等 | C++ | | | | |
| 62 | 不同路径 | 中等 | C++ | | | | |