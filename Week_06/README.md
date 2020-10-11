学习笔记 week6
=>本身递归、分治、回溯和动态规划没有实质性的区别。都是不停的处理重复子问题。
递归代码模板：
void recursion(int level, int param) {
	//recursion terminator
	if(level > max_level) {
		//process result;
		return;
}

//process current logic
process(level, param);

//drill down
recursion(level + 1, param);

//reverse the current level status if needed
}
分治代码模板：
int divide_conquer(Problem *problem, int params) {
	//recursion terminator
	if(problem == nullptr) {
		process_result
		return return_result;
}

//process current problem
subproblems = split_problem(problem, data);
subresult1 = divide_conquer(subproblem[0], p1);
subresult2 = divide_conquer(subproblem[1], p1);
…

//merge
result = process_result(subresult1, subresult2…);

revert the current level status

return 0;
}

感触：
1.人肉递归非常低效、很累。
2.一看就是复杂问题，那么肯定可以拆解成重复子问题。
3.数学归纳法思维，拒绝人肉递归。

=>本质是寻找重复性 ->用简单的计算机指令集来实现复杂的递归重复功能。
=>克服人肉递归的好办法：画状态树、找重复子状态，时间复杂度一目了然。
=>动态规划 = 分治 + 最优子结构。

DP和分治递归的共性：找到重复子问题。
差异性：最优子结构、中途可以淘汰次优解。

斐波那契数列
傻递归 -> 指数级的时间复杂度
处理方法：加一个数组当做缓存，把所有中间变量全部存下来。
与其从尾到头一步一步算，不如直接自顶向下

关键点：
1.最优子结构：opt[n] = best_of(opt[n-1], opt[n-2],…) =>找寻层级间关系。
2.存储中间状态：opt[i]
3.递推公式（状态转移方程）
Fib：opt[n] = opt[n-1] + opt[n-2]
二维路径：opt[i, j] = opt[i+1][j] + opt[i][j+1](且判断a[i, j]是否为空地)

LCS（最长公共子序列）都可以利用二维动态规划来做。

状态压缩：如果发现每次状态转移只需要DP table的一部分，那么就可以用状态压缩来缩小DP table的大小。
