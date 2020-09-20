学习笔记 week4
深度优先搜索和广度优先搜索：DFS和BFS
搜索遍历：每个节点访问一次，且仅访问一次。分为了深度优先、广度优先、优先度优先
深度优先遍历 – 栈、递归
=>模板：
map<int, int> visited;
void dfs(Node*root) {
        //terminator
	if(!root) return;
	
	if(visited.count(root->val)) {
		//already visited
		return;
	}

	visited[root->val] = 1;

	//process current node here
	// …
	for(int i = 0; i < root->children.size(); i++) {
		dfs(root->children[i]);
	}
	return;
}

特点：不会将当前子节点几访问完，而是对于任意一个节点一直下探直到叶节点。
广度优先遍历 – 队列 – 最短路径:每层节点先进入队列，然后将队列中节点弹出后将子节点进入队列。
=>模板：

void bfs(Node* root) {
	map<int, int> visited;
	if(!root) return;
	
	queue<Node*> queueNode;
	queueNode.push(root);

	while(!queueNode.empty()) {
		Node* node = queueNode.top();
		queueNode.pop();
		if(visited.count(node->val)) continue;
		visited[node->val] = 1;
		
		for(int i = 0; i < node->children.size(); i++) {
			queueNode.push(node.children[i]);
		}
	}
	return;
}

贪心算法：一种在每一步选择中选择最优结果，最终导致全局最佳的方法。
与动态规划的区别：贪心算法对每个解决方案作出选择，不能回退。动态规划是会保存以前的运算结果，并可以根据以前结果对当前进行选择，有回退功能。
=>总结：
贪心：当前局部最优判断
回溯：能够回退
动态规划：最优判断+回退
注：贪心不一定是最优结果，但一定是接近最优解。
主要解决最优化问题：比如最小生成树、哈夫曼编码等（剪绳子、选硬币）。
难点：1.能用贪心法的问题都有它的特殊性，需要能够证明可以得到最优解。 - 比如硬币问题，面值要成倍数。2.切入角度 – 从前贪心、从后贪心、中间切入贪心

二分查找：
关键的三个前提条件：1.单调性（必须有序或部分有序） 2.上下界3.索引
代码模板：
int binarySearch(const vector<int>& nums, int target) {
	int left = 0, right = (int)nums.size() – 1;
	
	while(left <= right) {
		int mid = left + (right - left) / 2; // 防止right+left越界
		if(nums[mid] == target) return mid;
		else if(nums[mid] < target) left = mid + 1;
		else right = mid – 1;
	}
	return -1;
}

牛顿迭代法： 迭代过程中以直线代替曲线，用一阶泰勒展开式代替原曲线，求直线与x轴的交点，重复该过程直到收敛。f(x) – f(x0) = f’(x0)(x – x0)

=>五毒神掌+四步解题：
	四步解题1 – 审题，确定题意
	四步解题2 – 探讨最优情况
	四步解题3 – 码代码
	四步解题4 – 测试用例：常规样例、错误样例、边界样例、变态样例
