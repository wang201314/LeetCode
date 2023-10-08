//给你一个整数数组 nums ，请计算数组的 中心下标 。
//
//数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
//
//如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。
//
//如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 - 1 。

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