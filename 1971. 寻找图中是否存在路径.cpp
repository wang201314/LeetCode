//有一个具有 n 个顶点的 双向 图，其中每个顶点标记从 0 到 n - 1（包含 0 和 n - 1）。图中的边用一个二维整数数组 edges 表示，
//其中 edges[i] = [ui, vi] 表示顶点 ui 和顶点 vi 之间的双向边。 每个顶点对由 最多一条 边连接，并且没有顶点存在与自身相连的边。
//
//请你确定是否存在从顶点 source 开始，到顶点 destination 结束的 有效路径 。
//
//给你数组 edges 和整数 n、source 和 destination，如果从 source 到 destination 存在 有效路径 ，则返回 true，否则返回 false 。

#include"leetcode.h"
using namespace std;
bool Solution::validPath(int n, vector<vector<int>>& edges, int source, int destination)
{
	vector<int>father(n);
	for (int i = 0; i < n; i++)
	{
		father[i] = i;
	}
	function<int(int)> find = [&](int t)->int
	{
		return t == father[t] ? t : father[t] = find(father[t]);
	};
	auto addedge = [&](int a,int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)
			return;
		father[b] = a;
	};
	auto isSame = [&](int a,int b)
	{
		a = find(a);
		b = find(b);
		return a == b;
	};
	for (auto vec : edges)
	{
		addedge(vec[0], vec[1]);
	}
	return isSame(source, destination);
}