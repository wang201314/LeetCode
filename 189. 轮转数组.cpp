//
//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
#include"leetcode.h"
using namespace std;
#if 0

void Solution::rotate(vector<int>& nums, int k)
{
	int n = nums.size();
	vector<int>vec(n, 0);
	for (int i = 0; i < n; i++)
	{
		vec[(i + k) % n] = nums[i];
	}
	nums = vec;
}
#elif 0

void Solution::rotate(vector<int>& nums, int k)
{
	int n = nums.size();
	k %= n;
	while(k--)
	{
		int temp = nums[n-1];
		int pre = nums[0];
		for (int i = 1; i < n; i++)
		{
			swap(pre, nums[i]);
		}
		nums[0] = temp;
	}
}
#elif 1

void Solution::rotate(vector<int>& nums, int k)
{
	k %= nums.size();
	reverse(nums.begin(),nums.end());
	reverse(nums.begin(), nums.begin()+k);
	reverse(nums.begin()+k, nums.end());
}
#elif 0

void Solution::rotate(vector<int>& nums, int k)
{

}
#endif


