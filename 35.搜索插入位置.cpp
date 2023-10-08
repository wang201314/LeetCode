//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//
//�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��

#include"leetcode.h"

using namespace std;
#if 1
int Solution::searchInsert(vector<int>& nums, int target)
{
	if (nums.size() == 0 || target < nums[0])
	{
		return 0;
	}
	if (target > nums[nums.size() - 1])
		return nums.size();
	int l = 0;
	int r = nums.size() - 1;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (nums[mid] > target)
		{
			r = mid - 1;
		}
		else if (nums[mid]<target)
		{
			l = mid + 1;
		}
		else
			return mid;
	}
	return l;
}
#endif