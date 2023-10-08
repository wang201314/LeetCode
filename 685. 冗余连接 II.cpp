//�ڱ������У��и���ָ�������������� ���� ͼ������ֻ��һ�����ڵ㣬���������ڵ㶼�Ǹø��ڵ�ĺ�̡��������˸��ڵ�֮���ÿһ���ڵ㶼����ֻ��һ�����ڵ㣬�����ڵ�û�и��ڵ㡣
//
//����һ������ͼ����ͼ��һ������ n ���ڵ㣨�ڵ�ֵ���ظ����� 1 �� n��������һ�����ӵ�����߹��ɡ����ӵı߰����� 1 �� n �е�������ͬ����䣬�������ӵı߲����������Ѵ��ڵıߡ�
//
//���ͼ��һ���Ա���ɵĶ�ά���� edges �� ÿ��Ԫ����һ��[ui, vi]�����Ա�ʾ ���� ͼ�����Ӷ��� ui �Ͷ��� vi �ıߣ����� ui �� vi ��һ�����ڵ㡣
//
//����һ����ɾ���ıߣ�ʹ��ʣ�µ�ͼ���� n ���ڵ���и��������ж���𰸣������������ڸ�����ά����Ĵ𰸡�
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