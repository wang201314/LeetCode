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
vector<int> Solution::searchRange(vector<int>& nums, int target)
{
	int n = nums.size();
	int l = 0;
	int r = n - 1;
	while (l <= r)
	{
		int mid = (l >> 1) + (r >> 1);
		if (nums[mid]>target)
		{
			r = mid - 1;
		}
		else if(nums[mid]<target)
		{
			l = mid + 1;
		}
		else
		{
			r = l = mid;
			break;
		}
	}
	if (nums[l] != target)
		return {-1,-1};
	while (l >= 0&&nums[l]==target)
	{
		l--;
	}
	while (r < n && nums[r] == target)
	{
		r++;
	}
	return {l+1,r-1};
}
#endif