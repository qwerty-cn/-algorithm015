学习笔记 week3
递归的实现、特性和思维要点：（Recursion）
本质类似于循环，通过函数体进行循环调用。 - 重复性（盗梦空间）
代码模板：
1.recursion terminator
2.process logic
3.drill down
4.reverse the states if needed.

=>注：1.不要人肉递归 2.拆解为重复子问题 3.数学归纳法思维（通项公式即递归函数体）

分治和回溯：递归的细分类
分治：典型：子集问题。
本质：找重复性，寻找和分析子问题，不断反复和迭代(还是递归)。
以字符串为例：小写转大写：分解成各个字符，然后每个字符小写转大写，最后合并。
代码模板：=>重要的问题：1.如何拆分子问题 2.如何合并
1.recursion terminator
2.prepare date（split big problem）
3.conquer subproblems
4.process and generate the final result（比递归多的一步，要将结果结合） - 相比递归，要在drill down这一步上进行一个merge操作
5.revert the current level states
回溯：试错的思想，如果没有找到正确答案，回溯返回重新计算。（八皇后、数独）

面试要点：
需要和面试官确认题目要求：比如是否可以调用库函数，变量的取值范围等等。
