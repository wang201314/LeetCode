//给定一个非负整数数组 nums，  nums 中一半整数是 奇数 ，一半整数是 偶数 。
//
//对数组进行排序，以便当 nums[i] 为奇数时，i 也是 奇数 ；当 nums[i] 为偶数时， i 也是 偶数 。
//
//你可以返回 任何满足上述条件的数组作为答案 。

#include"leetcode.h"

using namespace std;
#if 0
vector<int> Solution::sortArrayByParityII(vector<int>& nums)
{
	int n = nums.size();
	vector<int>ans(n,0);
	int odd = 1;
	int even = 0;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] % 2)
		{
			ans[odd] = nums[i];
			odd += 2;
		}
		else
		{
			ans[even] = nums[i];
			even += 2;
		}
	}
	return ans;
}
#elif 0
vector<int> Solution::sortArrayByParityII(vector<int>& nums)
{
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		if (nums[i] % 2 == 0 && i % 2 != 0)//奇数位上有偶数
		{
			for (int j = i+1;j<n;j+=2)//偶数位
			{
				if (nums[j] % 2 == 1)
				{
					swap(nums[i],nums[j]);
				}
			}
		}
		else if (nums[i] % 2 == 1 && i % 2 == 0)//偶数数位上有奇数
		{
			for (int j = i + 1; j < n; j += 2)//奇数位
			{
				if (nums[j] % 2 == 0)
				{
					swap(nums[i], nums[j]);
				}
			}
		}
	}
	return nums;
}
#elif 1
vector<int> Solution::sortArrayByParityII(vector<int>& nums)
{
	int n = nums.size();
	int odd = 1;
	for (int i = 0; i < n; i+=2)
	{
		if (nums[i]%2)//偶数位是奇数
		{
			while (nums[odd] % 2)
				odd += 2;
			swap(nums[i],nums[odd]);
		}
	}
	return nums;
}
#endif