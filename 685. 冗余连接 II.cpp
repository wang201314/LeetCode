//在本问题中，有根树指满足以下条件的 有向 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。
//
//输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。附加的边包含在 1 到 n 中的两个不同顶点间，这条附加的边不属于树中已存在的边。
//
//结果图是一个以边组成的二维数组 edges 。 每个元素是一对[ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是 vi 的一个父节点。
//
//返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
#include"leetcode.h"
using namespace std;
vector<int> Solution::findRedundantDirectedConnection(vector<vector<int>>& edges)
{
	int n = edges.size();
	vector<int>inDegree(n + 1,0);
	vector<int>father(n + 1);
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
	vector<int> res;
	for (auto&edge : edges)
	{
		if (find(edge[0]) == find(edge[1]))
		{
			ans = edge;
		}
		addedge(edge[0], edge[1]);
		if (++inDegree[edge[1]] > 1)
		{
			res = edge;
		}
	}
	if (res.empty())
		return ans;
	for (int i = 0; i <= n; i++)
	{
		father[i] = i;
	}
	for (auto&edge : edges)
	{
		if (edge == res)
			continue;
		if (edge[1] == res[1])
			ans = edge;
		if (find(edge[0]) == find(edge[1]))
		{
			return ans;
		}
		addedge(edge[0], edge[1]);
	}
	return  res;
}