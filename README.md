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
| 50 | Pow(x, n) | 中等 | Java | 快速幂 | 3 | 快速幂写错<br>边界值`Integer.MIN_VALUE`的处理（直接用`long`就好了嘛用什么`int`） | |
| 53 | 最大子序和 | 简单 | C++ | | | | |
| 54 | 螺旋矩阵 | 中等 | Java | 模拟，用`used`数组标记走过的位置，如果向前一步遇到走过的位置就改变方向 | 2 | 输入`matrix`为空，取`matrix[0].length`爆炸 | |
| 55 | 跳跃游戏 | 中等 | Java | 数组记录当前该位置是否可达，不可达则`return false`，可达且当前位置加可跳距离越过最后一个位置则`return true` | 1 | \ | |
| 56 | 合并区间 | 中等 | C++ | | | | |
| 62 | 不同路径 | 中等 | C++ | | | | |
| 70 | 爬楼梯 | 简单 | python | 简单dp，`dp[n] = dp[n-1] + dp[n-2]`，因为只用记录两个状态所以实际上不用dp数组 | 1 | \ | |
| 73 | 矩阵置零 | 中等 | python | 用两个数组记录每一列或每一行是否要清零（空间O(m+n)）<br>如果该行或该列要清零，则把该行或该列的第一个元素置零（第一行第一列需特殊标记），最后根据第一行第一列是否为0选择是否置零该行或该列（空间O(1)） | 1 | \ | |
| 75 | 颜色分类 | 中等 | python | 荷兰国旗问题，用两个指针`left`、`right`标记0的右边界和2的左边界 | 2 | 扫描到2，将`nums[right]`与当前位置元素交换后，当前位置的下标不应该加1，而是保持不变，因为从`nums[right]`交换过来的元素可能还需要被再次交换 | :exclamation::star: |
| 78 | 子集 | 中等 | python | 位运算，用二进制表示所有可能的子集取值情况。如对于`[1,2,3]`,000对应子集`[]`,101对应子集`[1,3]`<br>另有妙解：<br>`res = [[]]`<br/>        `for i in nums:`<br/>           `     res = res + [[i] + num for num in res]` | 1 | \ | :star: |
| 79 | 单词搜索 | 中等 | python | dfs裸题 | 1 | \ |  |
| 84 | 柱状图中最大的矩形 | 困难 | C++ | 单调栈，遇到比左边矮的柱子，就计算所有左边比他高的柱子所能向右扩展得到的最大面积。在所有柱子最后加个高度为0的柱子以清空栈 | 1 | \ | :exclamation: |
| 91 | 解码方法 | 中等 | C++ | 典型dp题，自己想的递推公式因为一开始没考虑存在0的情况所以很繁琐<br>优解：当前位为0时若前一位为1或2则`dp[i] = dp[i-1]`，否则不合法`return 0`。当前位不为0则看前一位，如果和前一位共同组成的数字在1~26范围内则`dp[i] = dp[i-1] + dp[i-2]`，分别代表两位拆开和不拆开的解码种数，否则`dp[i] = dp[i-1]`。注意到递推时实际上只用到`dp[i-1],dp[i-2]`，因此只需要`O(1)`空间 | 8 | s长度为0取长度为2的子串爆炸<br>没考虑0的情况<br>没考虑存在不合法串（00、30等）的情况 | :star: |
| 186 | 翻转字符串里的单词 | 中等 | C++ | 用`vector<string>`储存所有单词，反序输出即可<br>优解：把所有单词原地反序，再把整个序列全部反序，O(1)空间原地算法 | 1 | \ |  |
| 270 | 最接近的二叉搜索树值 | 简单 | C++ | 树的遍历，水 | 1 | \ | |
| 285 | 二叉搜索树中的顺序后继 | 中等 | Java | 中序遍历，但从左孩子返回后判断是否找到了目标节点，若找到则当前节点为目标节点的顺序后继。原因在于二叉搜索树中一个点只有可能是左子树中的某个结点的后继（左边都比他小，右边都比他大） | 4 | 未判断`cur.left != null`，若`cur`为目标节点且直接递归调了用`inorder(cur.left)`，`inorder()`发现`cur.left`是`null`后立即返回，`cur`发现左子树返回且当前状态为已找到目标节点，将`cur`错误设置为答案节点 | :star: |
| 348 | 判定井字棋胜负 | 中等 | C++ | 每行每列两对角线分别用int标记状态即可 | 3 | `int* a = new int[n]`<br>`sizeof(a) //大错！` |  |
| 651 | 4键键盘 | 中等 | C++ | dp。就用O(N^2)的方法，别把问题想太复杂。 | 3 | 只考虑了比较`dp[i-1] + (dp[i-1] - dp[i-2])`和`2*dp[i-3]`，实际上优解可能为`3*dp[i-4]`等 |  |
| 672 | 灯泡开关 II | 中等 | C++ | 方法一：第`x`盏灯始终等于第`x+6`盏灯。找出min(n,6)盏灯的m次操作排列数即可。因为操作2次及以上等于操作0或1次，且**进行 A 操作后接 B 操作 和 B 操作后接 A 操作是一样的，所以我们可以假设我们按顺序进行所有操作**。用位运算，遍历0~15即可表示所有可能的操作。将所有合法操作的结果加入set，最后返回set.size()<br>方法二：<br>`light1 = a + b + d`<br/>    `light2 = a + c`<br/>    `light3 = a + b`<br/>    `light4 = a + c + d = light2 + light1 - light3`<br/>    `light5 = a + b = light3`<br/>    `light6 = a + c = light2`<br/>    `light7 = a + b + d = light1`<br>由此可见排列数实际上等于前三盏灯的排列数。考虑min(n,3)的排列数即可。可以直接手动模拟出所有结果。 | 1 | \ | :exclamation::star: |
| 722 | 删除注释 | 中等 | C++ | 3种状态：0：正常，1：行注释，2：块注释<br>优解：状态机，每次根据1个字符而非两个改变状态。OJ词法分析器写过一遍了为什么不用这种高级的解法呢 | 6 | 万恶的/*/ | :star: |
| 886 | 可能的二分法 | 中等 | C++ | 交替染色，如果发现某结点与颜色相同的结点邻接则不能二分 | 3 | 没有考虑非连通图下有区域未染色的情况 | :exclamation::star: |
| 901 | 股票价格跨度 | 中等 | C++ | 单调栈 | 1 | \ | :exclamation::star: |
| 1006 | 笨阶乘 | 中等 | C++ | 数学规律 | 2 | n = 4的边界 |  |
| 1093 | 大样本统计 | 中等 | C++ | 简单统计，水 | 1 | \ |  |
| 1131 | 绝对值表达式的最大值 | 中等 | Java | 把表达式`\|arr1[i] - arr1[j]\| + \|arr2[i] - arr2[j]\| + \|i-j\|`看成三位曼哈顿距离的特例，在`{1,1,1},{1,1,-1},{1,-1,1},{1,-1,-1}`四个方向上找最大、最小值，求差，最大的差值即为解 | 1 | \ | :exclamation::star: |

