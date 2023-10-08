//�����Կ�����һ����ͨ�� �޻� �� ���� ͼ��
//
//������һ�� n ���ڵ�(�ڵ�ֵ 1��n) ���������һ���ߺ��ͼ����ӵıߵ�������������� 1 �� n �м䣬���������ӵı߲����������Ѵ��ڵı�
//��ͼ����Ϣ��¼�ڳ���Ϊ n �Ķ�ά���� edges ��edges[i] = [ai, bi] ��ʾͼ���� ai �� bi ֮�����һ���ߡ�
//
//���ҳ�һ������ɾȥ�ıߣ�ɾ�����ʹ��ʣ�ಿ����һ������ n ���ڵ����������ж���𰸣��򷵻����� edges �������ֵ��Ǹ���
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