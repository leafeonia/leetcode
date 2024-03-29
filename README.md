# leetcode

| ID | problem | 难度 | 使用语言 | 思路 | 提交次数 | WA点 | star |
| :---:  | :---: | :---: | :---:  | :---: | :---: | :---: | :---: |
| 1 | 两数之和 | 简单 | C++ | | | | |
| 2 | 两数相加 | 中等 | Java | 优解：当有一个链表到头的时候，用0代替其值 | | | |
| 3 | 无重复字符的最长子串  | 中等 | Java | | | | |
| 5 | 最长回文子串 | 中等 | python | 1. expand around center<br>2. dp | 2 | update index instead of answer string, otherwise tle | |
| 7 | 整数反转 | 简单 | python | | | | |
| 8 | 字符串转换整数(atoi) | 中等 | C++ | | | | |
| 11 | 盛最多水的容器 | 中等 | C++ | 双指针法 | | | :star: |
| 15 | 三数之和 | 中等 | C++ | | | | |
| 17 | 电话号码的字母组合 | 中等 | C++ | | | | |
| 19 | 删除链表的倒数第N个节点  | 中等 | C++ | | | | |
| 20 | 有效的括号 | 简单 | C++ | | | | |
| 21 | 合并两个有序链表 | 简单 | C++ | | | | |
| 22 | 括号生成 | 中等 | C++ | | | | |
| 23 | Merge k Sorted Lists | 困难 | C++ | heap | 1 | \ | :star: |
| 28 | 实现strStr() | 简单 | C++ | | | | |
| 29 | 两数相除（不使用乘法除法） | 中等 |  Java | 用被除数不断减去除数直至被减数为负（TLE），每次将减数翻倍 | 8 | 边界 | :star: |
| 31 | 下一个排列 | 中等 | C++ | 找到第一个比右边小的数，与右边比它大的最小的数交换，然后把它右边的数组部分整个翻转 | 3 | 右边存在多个相等的比它大的最小的数时，要取最右边的 |  |
| 33 | 搜索旋转排序数组 | 中等 | Java | | | | |
| 34 | 在排序数组中查找元素的第一个和最后一个位置 | 中等 | Java | 两次二分查找，先找左边界，再找右边界 | 1 | \ |  |
| 36 | 有效的数独 | 中等 | Java | 暴力，对所有行、所有列、所有九宫格分别检测(扫描243次)<br>优解：所有格子只遍历一次，根据`i`，`j`得出对应`row`、`column`、`block`的值，并判断这个值在上述三项的`Hashmap`中是否出现过(扫描81次) | 1 | \ |  |
| 39 | 组合总和 | 中等 | C++ | dp不可行（会出现重复情况）<br>用dfs：每次对当前下标对应的数字选0到最多个，然后下标++，target减去此处加上的总值，继续dfs，如果target为0则将vector加入答案中。因为下标递进且输入数组中数字各不相同，所以不可能重复 | 1 | \ | :star: |
| 40 | 组合总和II | 中等 | C++ | 与上一题区别在于输入数组中给出了各个数字的个数。关键在于避免重复，允许出现1->2->2->3，但不允许出现3<-2<-1->2->3.这就要求若扫描到与前一个数重复的数字，且该数字不是当前递归层的第一个可选数字，则放弃dfs该数。<br>1 \| 2 2，则第二个2不可选<br>1 2\|2，则第二个2可选 | 1 | \ | :star: |
| 41 | First Missing Positive | 困难 | C++ | The answer could only be integers in [1, n+1]. For every number `i` in this range, swap it to index `i - 1`. Finally, find the first position such that `nums[pos] != pos + 1` and return `pos + 1`. | 1 | \ | :exclamation::star: |
| 42 | Trapping Rain Water | 中等 | C++ | Iterate through columns. For each column, add `leftMax - height[i]` or `rightMax - height[i]` to `ans`, depending on whether `height[left] > height[right]`. Two pointers `left` and `right` are always on peak columns until another pointer moves on and surpasses it. | 2 | empty input | :star: |
| 46 | 全排列 | 中等 | Java | ~~用C++的`next_permutation`秒杀~~将已排列的部分递增，未排列的部分递减，递归即可。<br>优解：实现时，不必每次都传入新的已排列`List`和未排列`List`，只需要用`index`标记已排列和未排列区域的分界即可，使用`swap`将未排列区域的值交换到已排列区域，全程只需要一个`List`。 | 1 | \ | |
| 48 | 旋转图像 | 中等 | Java | 四条边上依次取一个对应位置进行顺序交换，只需O(1)存储空间存储第一个值，三变量交换的扩展<br>优解：将矩阵转置后左右对称交换，复杂度均为O(N^2)但思路与实现都更简单 | 2 | 下标表达式写错 | |
| 49 | 字母异位词分组 | 中等 | Java | 维护一个`Hashmap<String, List>`，以排序后的String作为key，将未排序的key加入value的List即可。对熟悉Hashmap基本操作很有帮助。 | 1 | \ | |
| 50 | Pow(x, n) | 中等 | Java | 快速幂 | 3 | 快速幂写错<br>边界值`Integer.MIN_VALUE`的处理（直接用`long`就好了嘛用什么`int`） | |
| 53 | Maximum Subarray | 简单 | C++ | Both greedy and dp work. if sum or dp[i-1] < 0, discard previous result and set sum or dp[i] as nums[i] | 2 | wrong method. (Not prefix sum) | :exclamation: |
| 54 | 螺旋矩阵 | 中等 | Java | 模拟，用`used`数组标记走过的位置，如果向前一步遇到走过的位置就改变方向 | 2 | 输入`matrix`为空，取`matrix[0].length`爆炸 | |
| 55 | 跳跃游戏 | 中等 | Java | 数组记录当前该位置是否可达，不可达则`return false`，可达且当前位置加可跳距离越过最后一个位置则`return true` | 1 | \ | |
| 56 | 合并区间 | 中等 | C++ | | | | |
| 62 | 不同路径 | 中等 | C++ | | | | |
| 64 | 最小路径和 | 中等 | C++ | 简单dp，注意可以inplace | 2 | 局部变量没初始化低级错误 | |
| 70 | 爬楼梯 | 简单 | python | 简单dp，`dp[n] = dp[n-1] + dp[n-2]`，因为只用记录两个状态所以实际上不用dp数组 | 1 | \ | |
| 72 | edit distance | 困难 | C++ | if (word1\[i - 1] == word2\[j - 1]) dp\[i][j] = dp\[i - 1][j - 1]<br>else dp\[i][j] = min(dp\[i - 1][j] /\*add after word1\*/, dp\[i][j - 1] /\*add after word2\*/, dp\[i - 1][j - 1] /\*replace last element of word1\*/) + 1 | 1 | \ | :exclamation::star: |
| 73 | 矩阵置零 | 中等 | python | 用两个数组记录每一列或每一行是否要清零（空间O(m+n)）<br>如果该行或该列要清零，则把该行或该列的第一个元素置零（第一行第一列需特殊标记），最后根据第一行第一列是否为0选择是否置零该行或该列（空间O(1)） | 1 | \ | |
| 74 | 搜索二维矩阵 | 中等 | C++ | 从右往左，若该列第1个值比target值大则继续向左，否则向下找(剑指offer面试题4) | 2 | 边界 | |
| 75 | 颜色分类 | 中等 | python | 荷兰国旗问题，用两个指针`left`、`right`标记0的右边界和2的左边界 | 2 | 扫描到2，将`nums[right]`与当前位置元素交换后，当前位置的下标不应该加1，而是保持不变，因为从`nums[right]`交换过来的元素可能还需要被再次交换 | :exclamation::star: |
| 78 | 子集 | 中等 | python | 位运算，用二进制表示所有可能的子集取值情况。如对于`[1,2,3]`,000对应子集`[]`,101对应子集`[1,3]`<br>另有妙解：<br>`res = [[]]`<br/>        `for i in nums:`<br/>           `     res = res + [[i] + num for num in res]` | 1 | \ | :star: |
| 79 | 单词搜索 | 中等 | python | dfs裸题 | 1 | \ |  |
| 81 | 搜索旋转排序数组II | 中等 | Java | 二分，left值小于mid值则左侧有序，如果target值大于等于left值小于mid值则接着在左边找，否则在右边找。left值大于mid值则右侧有序，如果target值在右侧有序范围内则在右边找，否则左边找。如果left = mid，不知道在哪边，则直接left++ | 2 | 二分时`while(left <= right)`而非`while(left < right)`，否则长度为1时不正确 | :exclamation::star: |
| 84 | 柱状图中最大的矩形 | 困难 | C++ | 单调栈，遇到比左边矮的柱子，就计算所有左边比他高的柱子所能向右扩展得到的最大面积。在所有柱子最后加个高度为0的柱子以清空栈 | 1 | \ | :exclamation: |
| 91 | 解码方法 | 中等 | C++ | 典型dp题，自己想的递推公式因为一开始没考虑存在0的情况所以很繁琐<br>优解：当前位为0时若前一位为1或2则`dp[i] = dp[i-1]`，否则不合法`return 0`。当前位不为0则看前一位，如果和前一位共同组成的数字在1~26范围内则`dp[i] = dp[i-1] + dp[i-2]`，分别代表两位拆开和不拆开的解码种数，否则`dp[i] = dp[i-1]`。注意到递推时实际上只用到`dp[i-1],dp[i-2]`，因此只需要`O(1)`空间 | 8 | s长度为0取长度为2的子串爆炸<br>没考虑0的情况<br>没考虑存在不合法串（00、30等）的情况 | :star: |
| 93 | Restore IP Addresses | 中等 | C++ | dfs | 1 | \ |  |
| 94 | 二叉树的中序遍历 | 中等 | C++ | 递归:trivial<br>循环：用`map<Node*, bool> mp`记录当前结点是否之前遇到过，如果没有则向栈中push右、自身、左，并赋值`mp[cur] = true`，否则向结果向量中添加当前结点value。循环至栈空为止 | 1 | \ |  |
| 95 | 不同的二叉搜索树II | 中等 | C++ | dp,`dp[i][j]`存储包含从`i`到`j`的所有二叉搜索树的根节点，所有子树从小到大拼到最大的二叉树 | 2 | n=0 | |
| 96 | 不同的二叉搜索树 | 中等 | C++ | 上题dp方法<br>优解：用一维dp数组即可，因为此时求的是所有可能的二叉搜索树的个数，故1,2,3,4组成的二叉搜索树的个数与3,4,5,6相同，都用dp[4]存储即可。 | 1 |  | |
| 98 | 验证二叉搜索树 | 中等 | C++ | 递归(cur, min, max)<br>妙解：中序遍历，二叉搜索树的中序遍历序列应当严格增 | 3 | long long，请 | |
| 99 | Recover Binary Search Tree | 中等 | C++ | inorder traverse the BST along with recording the previous treenode. For the first time if prev->val > root->val then `big = prev; small = root`(1,3,2,4). For the second time set `small = root`(1,2,6,4,3,5). Swap value of big and small. | 3 | Finding only small is not enough | :exclamation: |
| 115 | Distinct Subsequences | 困难 | C++ | dp\[i][j] = dp\[i][j - 1]<br>if (t[i - 1] == s[j - 1]) dp\[i][j] += dp\[i - 1][j - 1]<br>for (int j = 0; j <= s.length(); j++) dp\[0][j] = 1 | 2 | long long，请 | |
| 120 | 三角形最小路径和 | 中等 | C++ | 简单自底向上dp，dp数组只用一维即可 | 1 | \ | |
| 127 | Word Ladder | 困难 | C++ | bfs | 3 | TLE. Do not search wordList to find next, change characters of current word instead. Takes only (26*WordLength). <br>Remove searched word from wordList instead of using `visited`. TLE->AC | |
| 129 | 求根到叶子结点数字之和 | 中等 | C++ | 把上层结点的值存在vector里往下传<br>优解：把上层结点的值用一个数字表示往下传即可 | 2 | 一边null一边有子节点 | |
| 139 | 单词拆分 | 中等 | C++ | 记忆化搜索<br>dp:`dp[i] = true`表示单词的前i位可以用词表表示，若`dp[i]`为`true`且单词的第`i`到`j`位在词表中则`dp[j]`为`true`。 | 2 | 一开始用set只记了成功的情况导致TLE，换成map把成功和失败的子串都记录即可 | |
| 146 | LRU Cache | 中等 | C++ | unordered_map + double linked list. Use 2 sentinels (head and tail) | 2 | linked list should also be updated after put | :exclamation::star: |
| 173 | Binary Search Tree Iterator | 中等 | C++ | Simulate recursion by stack. if a node has right child, while the child has left child recursively push left child into stack. | 1 | \ | :exclamation::star: |
| 186 | 翻转字符串里的单词 | 中等 | C++ | 用`vector<string>`储存所有单词，反序输出即可<br>优解：把所有单词原地反序，再把整个序列全部反序，O(1)空间原地算法 | 1 | \ |  |
| 198 | House Robber | 中等 | C++ | dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]) | 1 | \ | |
| 207 | Course Schedule | 中等 | C++ | 拓扑排序 | 1 | \ | |
| 210 | Course Schedule II | 中等 | C++ | Topological sort | 1 | \ | |
| 211 | Design Add and Search Words Data Structure | 中等 | C++ | Application of Trie | 4 | Use isEnd to check end<br>incorrect end condition of recursion | |
| 213 | House Robber II | 中等 | C++ | ans = max(houseRobber(0, n - 2), houseRobber(1, n - 1)) | 2 | n == 2的情况 | |
| 220 | 存在重复元素III | 中等 | C++ | 双指针法，用set管理双指针内的区间，实现log(n)级别的查找 | 7 | 半年没刷题 复健两行泪 | :star: |
| 222 | 完全二叉树的节点个数 | 中等 | C++ | 从右往左，如果到最深一层的节点为空则`cnt++`，直至找到第一个在最深一层的非空节点，答案为`2^h - 1 - cnt` | 1 |  | |
| 224 | Basic Calculator | 困难 | C++ | Because only + and - exist in the expression so whenever we meet a number we add it or minus it to the ans. The only thing to do is to set the correct sign. Use stack to store signs. <br>+ : sign = st.top() <br> - : sign = -st.top()<br> ( : st.push(sign)<br>) : st.pop()<br>This logic can handle negative numbers directly. | 1 | \ | :star: |
| 227 | Basic Calculator II | 中等 | C++ | store previous operator (initialized as '+'). When a new operator is encountered or reaching the end of string, push new num value into stack according to previous operator, then store current operator as the new previous operator. Add all the number in the stack to achieve the final value (if previous operator is '-', push -num into stack) | 2 | 214748364 * 10 + ch - '0' overflow | :star: |
| 236 | 二叉树的最近公共祖先 | 中等 | C++ | 递归，左侧找到点+右侧找到点+自己是所找点 = 2的点即为所求 | 2 | 自己是所找点时，不能立即return，仍然要向下递归 | :star: |
| 238 | Product of Array Except Self | 中等 | C++ | From left to right producting nums one by one to fill the `ans` with left side product. Then track the right side product from right to left by a single variable, and multiply it with elements in `ans` to get the product of both sides. O(1) space | 1 | \ |  |
| 241 | Different Ways to Add Parentheses | 中等 | C++ | dfs | 1 | \ | |
| 253 | Meeting Rooms II | 中等 | C++ | Sort the intervals by **start time** (different from merge intervals) and push finish time to a minheap. If current start time >= minheap.top then pop minheap top. Answer is the size of the minheap. | 1 | \ | :star: |
| 269 | Alien Dictionary | 困难 | C++ | Topological sort | 5 | check that word2 is not a prefix of word1<br>indegree may have been updated for a repeated edge | :star: |
| 270 | 最接近的二叉搜索树值 | 简单 | C++ | 树的遍历，水 | 1 | \ | |
| 285 | 二叉搜索树中的顺序后继 | 中等 | Java | 中序遍历，但从左孩子返回后判断是否找到了目标节点，若找到则当前节点为目标节点的顺序后继。原因在于二叉搜索树中一个点只有可能是左子树中的某个结点的后继（左边都比他小，右边都比他大） | 4 | 未判断`cur.left != null`，若`cur`为目标节点且直接递归调了用`inorder(cur.left)`，`inorder()`发现`cur.left`是`null`后立即返回，`cur`发现左子树返回且当前状态为已找到目标节点，将`cur`错误设置为答案节点 | :star: |
| 300 | Longest Increasing Subsequence | 中等 | C++ | for (int j = 0; j < i; j++) dp[i] = max(dp[i], dp[j] + 1)<br>O(NlogN) solution: define vector tails, and tails[i] denotes the minimum tail value for a increasing subsequence with length i+1. If the new element is bigger than the end of tail then push_back it, otherwise find its lower_bound place and replace the original value. The final answer is tails.size() | 2 | the answer is not dp[n-1]! |  |
| 310 | Minimum Height Trees | 中等 | C++ | find the centre of the graph (no more than 2, contradiction can be used to prove this) by removing all the leaves round by round until no more than 2 nodes left | 1 | \ | :exclamation: |
| 337 | House Robber III | 中等 | C++ | search with memorization | 2 | ignored max |  |
| 348 | 判定井字棋胜负 | 中等 | C++ | 每行每列两对角线分别用int标记状态即可 | 3 | `int* a = new int[n]`<br>`sizeof(a) //大错！` |  |
| 373 | Find K Pairs with Smallest Sums | 中等 | C++ | View the problem as k-way merge:<br>{nums1[0], nums2[0]}->{nums1[0], nums2[1]}<br>{nums1[1], nums2[0]}->{nums1[1], nums2[0]}<br>{nums1[2], nums2[0]}->{nums1[2], nums2[0]} | 2 | 2 pointers (wrong method) | |
| 378 | Kth Smallest Element in a Sorted Matrix | 中等 | C++ | K-way merge | 1 | \ | |
| 380 | Insert Delete GetRandom O(1) | 中等 | C++ | hashmap + vector. For insert and getrandom, vector can finish them in O(1) naturally. For delete, swap the value to the end of the vector then pop it. To get the index of the value, use a hashmap for O(1) time complexity. | 4 | Update hashmap twice after delete.<br>Do not use srand(time(0)) | :exclamation::star: |
| 394 | Decode string | 中等 | C++ | Stack or recursion. Recursion solution: for each level, if char is encountered, add it directly to `ret`; if number is encountered, get the number value `num` until meeting '[', then recursively get the value of a deeper level and add it `num` times to `ret`. ']' or end of original string mark the end of current level. Return `ret` to previous level in this case. | 2 | Do not store char value in variable out of stack if using stack. | :star: |
| 399 | Evaluate Division | 中等 | C++ | dfs<br>other solutions: floyd, union-find with weights | 2 | forget to consider loops | |
| 403 | 青蛙过河 | 困难 | C++ | 记忆化dfs | 4 | 不仅失败的路径要记忆，成功的路径也要记忆 | |
| 408 | Valid Word Abbreviation | 简单 | C++ | processing string. <br>while (ptr1 < a.le() && ptr2 < b.le()) {} <br>return ptr1 == a.le() && ptr2 == b.le(); | 4 | return false if start of number is 0 | fb |
| 416 | Partition Equal Subset Sum | 中等 | C++ | find whether 01 knapsack solution exists. | 1 | \ | :exclamation::star: |
| 426 | Convert Binary Search Tree to Sorted Doubly Linked List | 中等 | C++ | Record prev Node during the process of inorder traversal. Update left and right for current node and prev, then update current node as prev. | 2 |  |  |
| 457 | Circular Array Loop | 中等 | C++ | fast and slow pointer, use `((i + nums[i]) % n + n) % n` to simulate circle | 4 | 1. (num%n+n)%n<br>2. Check sign for next pointer, not slow, because some invalid signs can only be met by fast pointer | :star: |
| 474 | Ones and Zeroes | 中等 | C++ | 2d 01 knapsack | 1 | \ |  |
| 494 | Target Sum | 中等 | C++ | find 01 knapsack solution number. `dp[i]` is the number of solution that the sum of positive numbers is i.  Return dp[(sum + target)/2]<BR>x : sum of all positive numbers<br>x - (sum - x) = target<br>x = (sum + target) / 2 | 1 | \ | :exclamation::star: |
| 496 | Next Greater Element I | 简单 | C++ | monotone stack | 1 | \ | |
| 501 | Find Mode in Binary Search Tree | 简单 | C++ | solution with O(1) space: use in-order traverse because the tree is a BST, the traversed list will be sorted. So we can count the times a number appears without additional space. If the time count is greater than current record, then clear the ans vector and push_back it, along with updating the record. | 1 | \ | |
| 503 | Next Greater Element II | 中等 | C++ | monotone stack, the content in stack is index, not value. use `% n` to realize circulation | 1 | \ | |
| 510 | 二叉搜索树的中序后继II | 中等 | C++ | 有右孩子则找右子树中最小的，否则向上找到第一个比自己大的父节点 | 1 | \ | |
| 516 | Longest Palindromic Subsequence | 中等 | C++ | if (s[i] == s[j]) dp\[i][j] = dp\[i + 1][j - 1] + 2;<br/>else dp\[i][j] = max(dp\[i + 1][j], dp\[i][j - 1]); | 1 | \ | |
| 523 | Continuous Subarray Sum | 中等 | C++ | store {runningSum % k, index} into map. If map[runningSum % k] is not empty and the difference of index is greater than 1, then we find a range between two the indexes whose sum % k = 0. | 2 | Init map with {0,-1} | :exclamation: |
| 542 | 01 Matrix | 中等 | C++ | bfs starting with 0. Dye "1" cells step by step from outer to inner. | 1 | \ | |
| 554 | 砖墙 | 中等 | C++ | 用map统计前缀和数组中出现最多的数 | 2 | 暴力枚举不可取 | |
| 560 | Subarray Sum Equals K | 中等 | C++ | Use a map to record how many times a prefix sum has appeared. Then for each number `n` in the array, add mp[n - k] to the answer. | 1 | \ | :exclamation::star: |
| 581 | Shortest Unsorted Continuous Subarray | 中等 | C++ | find `right` - the index of the rightmost element which is smaller than the max value of its left elements, as well as `left`. Return `right - left + 1`. | 1 | \ | |
| 583 | Delete Operation for Two Strings | 中等 | C++ | word1.length() + word2.length() - 2 * longest common subsequence(word1, word2) | 1 | \ | |
| 591 | 标签验证器 | 困难 | C++ | 根据字符切换`begin`,`normal`,`tag_start`,`tag_end`,`CDATA`五个状态，用栈存储遇到的tag | 3 | 1. 缺了开头结尾的tag，直接CDATA<br>2. <\<A>\</A>的第二个`<` | |
| 631 | 设计Excel求和公式 | 困难 | C++ | 把公式存起来，每次获取值之前计算所有的公式把值更新 | 3 | 用值覆盖公式时要将当前位置存储的公式删掉 | |
| 633 | 平方数之和 | 中等 | C++ | a从0遍历到$\sqrt c$，判断$c - a^2$是不是平方数 | 1 | \ | |
| 647 | Palindromic Substrings | 中等 | C++ | expand possible centers. Note that string with length n has 2n - 1 centers. (Consider: "aa")<br>if using dp, dp\[i][j] is a boolean value denoting whether s[i .. j] is palindrome | 1 | \ | |
| 651 | 4键键盘 | 中等 | C++ | dp。就用O(N^2)的方法，别把问题想太复杂。 | 3 | 只考虑了比较`dp[i-1] + (dp[i-1] - dp[i-2])`和`2*dp[i-3]`，实际上优解可能为`3*dp[i-4]`等 |  |
| 670 | Maximum Swap | 中等 | C++ | Iterate from right to left. If a number is smaller than current biggest value, then update the indexes to swap as the indexes of this number and current biggest number. | 1 |  | f​b:star: |
| 672 | 灯泡开关 II | 中等 | C++ | 方法一：第`x`盏灯始终等于第`x+6`盏灯。找出min(n,6)盏灯的m次操作排列数即可。因为操作2次及以上等于操作0或1次，且**进行 A 操作后接 B 操作 和 B 操作后接 A 操作是一样的，所以我们可以假设我们按顺序进行所有操作**。用位运算，遍历0~15即可表示所有可能的操作。将所有合法操作的结果加入set，最后返回set.size()<br>方法二：<br>`light1 = a + b + d`<br/>    `light2 = a + c`<br/>    `light3 = a + b`<br/>    `light4 = a + c + d = light2 + light1 - light3`<br/>    `light5 = a + b = light3`<br/>    `light6 = a + c = light2`<br/>    `light7 = a + b + d = light1`<br>由此可见排列数实际上等于前三盏灯的排列数。考虑min(n,3)的排列数即可。可以直接手动模拟出所有结果。 | 1 | \ | :exclamation::star: |
| 690 | 员工的重要性 | 简单 | C++ | 先用map整理数据，之后dfs | 1 | \ |  |
| 708 | 循环有序列表的插入 | 中等 | JS | 先找到循环起点，再从起点出发找合适的插入点 | 4 | 非严格递增<br>JS语法 |  |
| 708 | Insert into a Sorted Circular Linked List | 中等 | C++ | Insert when 1)  the value sits between two nodes 2) the value >= maximum or <= minimum (to judge maximum or minimum, values in linkedlist cannot all be the same) 3) the linkedlist values are all the same<br>lastnode = head<br>while (lastnode->next != head) {<br>if (lastnodeVal <= val <= nodeval) \|\|<br>val is the minimum \|\| <br>val is the maximum) break;}<br>add the new node after lastnode | 2 | values in the linkedlist are all the same | :star: |
| 718 | Maximum Length of Repeated Subarray | 中等 | C++ | if (nums1[i - 1] == nums2[j - 1]) dp\[i][j] = dp\[i - 1][j - 1]+1<br>reduce memory to O(N): <br>if (nums1[i - 1] == nums2[j - 1]) dp[j] = dp[j - 1]+1<br>**else dp[j] = 0**<br>iterate in reverse order<br>return maxvalue, not dp\[m][n] | 2 | else dp[j] = 0 | :exclamation::star: |
| 721 | Accounts Merge | 中等 | C++ | union find, merge id of emails, not user | 3 | TLE, merged users by union find | :exclamation: |
| 722 | 删除注释 | 中等 | C++ | 3种状态：0：正常，1：行注释，2：块注释<br>优解：状态机，每次根据1个字符而非两个改变状态。OJ词法分析器写过一遍了为什么不用这种高级的解法呢 | 6 | 万恶的/*/ | :star: |
| 735 | Asteroid Collision | 中等 | C++ | using stack. Only handle collision when st.top() > 0 (rightward) && cur < 0 (leftward) | 1 | \ |  |
| 752 | Open the lock | 中等 | C++ | bfs | 1 | \ |  |
| 792 | Number of Matching Subsequences | 中等 | C++ | Iterate through `s` only once to avoid TLE. Store all words in 26 buckets according to the first character.  For every char of `s`, move forward the index of words in bucket[ch] and move them to the new bucket according to the new first character. If the index reaches the end of a word, `ans++` | 3 | TLE<br>If use vector as bucket, clear the bucket first then push_back new elements. A better solution uses queue instead. | :star::exclamation: |
| 802 | Find Eventual Safe States | 中等 | C++ | Method1: Reverse the original graph, then do topological sort to detect cycle<br>Method2: dfs with color, and do not clear the color when returning from recursion. | 2 | naive dfs with color clearance -> tle | :exclamation: |
| 839 | Similar String Groups | 困难 | C++ | union find | 2 | bug in checking whether 2 strings are swapable |  |
| 843 | Guess the word | 困难 | C++ | general idea: select a word `w`,  eliminate all the words in wordlist that match(w, word) != master.guess(w)<br>How to select `w`? Since the probability that master.guess(w) = 0 is (25/26)^6 ≈ 0.8, AND we want to eliminate as many words as possible. So we can assume that master.guess(w) returns 0 and select the word `w` as the word that has most matches with other words in wordlist. | 2 | The algorithm never guarantees successful guess. For wordlist {"aaaaaa", "bbbbbb", ..., "zzzzzz"} it is impossible to guess the word in 10 guesses. | :exclamation: |
| 856 | Score of Parentheses | 中等 | C++ | Using stack, when `)` is met,`a = s.pop(), b = s.pop(), s.push_back(b + max(1, 2 * a)) `<br>optimal solution: when `()` is detected, add `pow(2, depth)` to answer | 1 | \ | |
| 886 | 可能的二分法 | 中等 | C++ | 交替染色，如果发现某结点与颜色相同的结点邻接则不能二分 | 3 | 没有考虑非连通图下有区域未染色的情况 | :exclamation::star: |
| 901 | 股票价格跨度 | 中等 | C++ | 单调栈 | 1 | \ | :exclamation::star: |
| 907 | Sum of Subarray Minimums | 中等 | C++ | use monotone stacks to find the left boundry and right boundry among which arr[i] is the smallest, then `ans += arr[i] * (i - left) * (right - i)`.  Notice that for contiguous same elements, only count the range in one direction | 4 | mod 1e9+7 |  |
| 952 | Largest Component Size by Common Factor | 困难 | C++ | use union find to merge every number with all its factors | 1 | \ | :exclamation: |
| 974 | Subarray Sums Divisible by K | 中等 | C++ | ans += mp[(sum % k + k) % k] | 3 | Incorrect Algorithm(TLE). Did not handle minus sum % k correctly. | :star: |
| 981 | Time Based Key-Value Store | 中等 | C++ | unordered_map<key, {timestamp, value}> with binary search on timestamp | 1 | \ |  |
| 990 | Satisfiability of Equality Equations | 中等 | C++ | union find | 1 | \ |  |
| 1006 | 笨阶乘 | 中等 | C++ | 数学规律 | 2 | n = 4的边界 |  |
| 1035 | Uncrossed Lines | 中等 | C++ | The same as 1143 Longest Common Subsequence | 1 | \ | |
| 1041 | Robot Bounded In Circle | 中等 | C++ | After finishing all the instructions, if the robot does not face north then there is a cycle. | 1 | \ | |
| 1048 | Longest String Chain | 中等 | C++ | sort by length then dp. dp is a map, not vector, which gives a time complexity of O(NlogN) | 1 | \ | |
| 1049 | Last Stone Weight II | 中等 | C++ | 01 knapsack.  Divide stones to two parts with smallest weight difference, answer = bigWeight - smallWeight = sum - 2 * smallWeight. To find the smallWeight, understand the problem as 01 knapsack with bag weight of sum / 2 and find the maxValue. The weight and value of a stone is the same. | 1 | \ | :exclamation::star: |
| 1053 | 交换一次的先前排列 | 中等 | C++ | 从右向左找第一个比右边任意一个大的数，并且把他右边最大的一个和他交换 | 2 | 正序改逆序忘了改for循环的0 | :star: |
| 1093 | 大样本统计 | 中等 | C++ | 简单统计，水 | 1 | \ |  |
| 1130 | Minimum Cost Tree From Leaf Values | 中等 | C++ | search with memorization<br>optimal solution: monotone stack | 1 | \ | |
| 1131 | 绝对值表达式的最大值 | 中等 | Java | 把表达式`\|arr1[i] - arr1[j]\| + \|arr2[i] - arr2[j]\| + \|i-j\|`看成三位曼哈顿距离的特例，在`{1,1,1},{1,1,-1},{1,-1,1},{1,-1,-1}`四个方向上找最大、最小值，求差，最大的差值即为解 | 1 | \ | :exclamation::star: |
| 1143 | Longest Common Subsequence | 中等 | C++ | if (text1[i - 1] == text2[j - 1])  dp\[i][j] = dp\[i - 1][j - 1] + 1<br>  else dp\[i][j] = max(dp\[i][j - 1], dp\[i - 1][j]) | 2 | cannot directly use 1d array to optimize memory usage (have to add another variable to track dp\[i-1][j-1] if you want) | :star: |
| 1202 | Smallest String With Swaps | 中等 | C++ | 用并查集合并连通分量，之后把每个连通分量中的字符存储在vector中并排序，最后遍历下标`i`，把`s[i]`更新为`findSet(i).back()`后`pop_back()`掉vector末字典序最小的字符 | 1 | \ | :exclamation: |
| 1249 | Minimum Remove to Make Valid Parentheses | 中等 | C++ | remove invalid ')' first, then remove redundant '(' from right to left | 2 | did not remove redundant '(': ()( |  |
| 1277 | Count Square Submatrices with All Ones | 中等 | C++ | dp\[i][j] means the size of biggest square with matrix\[i][j] as the bottom-right corner. dp\[i][j] = min(dp\[i-1][j-1], dp\[i-1][j], dp\[i][j-1]) + 1 | 1 | \ | :exclamation: |
| 1391 | 检查网格中是否存在有效路径 | 中等 | C++ | dfs，每个位置有两种可能的搜索方向，要根据到来的方向选择其中之一 | 2 | 即使到了终点，进入方向对才是对 |  |
| 1428 | Leftmost Column with at Least a One | 中等 | C++ | binary search. Search row by row is better because we can set `high` as ans - 1<br>Better solution: search from top-right corner. If we meet an 1, move left; otherwise move down. Final answer is the column + 1 | 1 | \ | |
| 1509 | Minimum Difference Between Largest and Smallest Value in Three Moves | 中等 | C++ | min(nums[n - 4] - nums[0], nums[n - 3] - nums[1], nums[n - 2] - nums[2], nums[n - 1] - nums[3]) (after sorting) | 1 | \ | |
| 1650 | Lowest Common Ancestor of a Binary Tree III | 中等 | C++ | move two pointers from p, q resepectively to their parents. If it becomes null assign it to the another original node. The node where two pointers meet is the answer. | 1 | \ | |
| 1734 | 解码异或后的排列 | 中等 | C++ | 将encoded数组除第一项之外每隔一项进行异或，得到$p[1]$^ $p[2]$^...^$p[n-1]$，由题目条件可计算$p[0]$^ $p[1]$^...^$p[n-1]$，两者异或得$p[0]$，之后传导求解 | 1 | \ | :question: |
| 1792 | Maximum Average Pass Ratio | 中等 | C++ | Use priority_queue. Subtract 1 from extraStudents every time and update the pq. | 2 | use a/b/c instead of a/(b*c). May lead to overflow |  |
| offer3 | 数组中重复的数字 | 简单 | C++ | 下标统计，把数字换到以它自身作为下标的位置，如果该位置已有数字相同则重复 | 1 | \ |  |
| offer4 | 二维数组中的查找 | 简单 | C++ | 线性查找，从右上到左下 | 1 | \ | |
| offer7<br>(105) | 重建二叉树 | 中等 | C++ | 先序中序还原树。递归，注意递归时先序左右边界和中序左右边界 | 1 | \ | |
| offer12 | 矩阵中的路径 | 中等 | C++ | dfs<br>优解：不用visited数组，走过的格子内容改成'0'即可 | 2 | 先判断终止条件再判断是否越过边界 | |
| offer13 | 机器人的运动范围 | 中等 | C++ | dfs | 2 | 这题visited数组在dfs结束后不重置 | :exclamation: |
| offer26 | 树的子结构 | 中等 | C++ | 对A树中每个结点，判断以该结点为根的子树中是否包含B | 4 | 思路不对，不能用先序遍历序列判断<br>树中可能有值相同的结点 | :question: |

