//����һ���Ǹ��������� nums��  nums ��һ�������� ���� ��һ�������� ż�� ��
//
//��������������Ա㵱 nums[i] Ϊ����ʱ��i Ҳ�� ���� ���� nums[i] Ϊż��ʱ�� i Ҳ�� ż�� ��
//
//����Է��� �κ���������������������Ϊ�� ��

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
		if (nums[i] % 2 == 0 && i % 2 != 0)//����λ����ż��
		{
			for (int j = i+1;j<n;j+=2)//ż��λ
			{
				if (nums[j] % 2 == 1)
				{
					swap(nums[i],nums[j]);
				}
			}
		}
		else if (nums[i] % 2 == 1 && i % 2 == 0)//ż����λ��������
		{
			for (int j = i + 1; j < n; j += 2)//����λ
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
		if (nums[i]%2)//ż��λ������
		{
			while (nums[odd] % 2)
				odd += 2;
			swap(nums[i],nums[odd]);
		}
	}
	return nums;
}
#endif