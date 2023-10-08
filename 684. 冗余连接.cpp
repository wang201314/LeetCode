//树可以看成是一个连通且 无环 的 无向 图。
//
//给定往一棵 n 个节点(节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边
//。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。
//
//请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的那个。
#include"leetcode.h"
using namespace std;

vector<int> Solution::findRedundantConnection(vector<vector<int>>& edges)
{
	int n = edges.size();
	vector<int>father(n+1);
	for (int i = 0; i <= n; i++)
	{
		father[i] = i;
	}
	function<int(int)> find = [&](int t)->int
	{
		return t == father[t] ? t : father[t] = find(father[t]);
	};
	auto addedge = [&](int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)
			return;
		father[b] = a;
	};
	vector<int>ans;
	for (auto&edge : edges)
	{
		if (find(edge[0]) == find(edge[1]))
		{
			ans = edge;
		}
		addedge(edge[0], edge[1]);
	}
	return ans;
}