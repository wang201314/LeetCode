//����һ���������� nums ������������ �����±� ��
//
//���� �����±� �������һ���±꣬���������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�
//
//��������±�λ����������ˣ���ô�����֮����Ϊ 0 ����Ϊ���±����಻����Ԫ�ء���һ����������±�λ���������Ҷ�ͬ�����á�
//
//��������ж�������±꣬Ӧ�÷��� ������ ����һ����������鲻���������±꣬���� - 1 ��

#include"leetcode.h"

using namespace std;
#if 1
int Solution::pivotIndex(vector<int>& nums)
{
	int n = nums.size();
	vector<int>pre(n + 1, 0);
	int rsum = 0;
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + nums[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (pre[i] == rsum)
		{
			return i;
		}
		rsum += nums[i];
	}
	return -1;
}
#elif
int Solution::pivotIndex(vector<int>& nums)
{
	int n = nums.size();
	int sum = 0;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += nums[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (2 * sum + nums[i] == total)
		{
			return i;
		}
		sum += nums[i];
	}
	return -1;
}
#endif