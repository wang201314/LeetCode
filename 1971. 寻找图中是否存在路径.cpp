//��һ������ n ������� ˫�� ͼ������ÿ�������Ǵ� 0 �� n - 1������ 0 �� n - 1����ͼ�еı���һ����ά�������� edges ��ʾ��
//���� edges[i] = [ui, vi] ��ʾ���� ui �Ͷ��� vi ֮���˫��ߡ� ÿ��������� ���һ�� �����ӣ�����û�ж�����������������ıߡ�
//
//����ȷ���Ƿ���ڴӶ��� source ��ʼ�������� destination ������ ��Ч·�� ��
//
//�������� edges ������ n��source �� destination������� source �� destination ���� ��Ч·�� ���򷵻� true�����򷵻� false ��

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