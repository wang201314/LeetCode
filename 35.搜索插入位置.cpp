//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//请必须使用时间复杂度为 O(log n) 的算法。

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