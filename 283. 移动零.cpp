//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
//
//��ע�� �������ڲ���������������ԭ�ض�������в�����
#include"leetcode.h"
using namespace std;
void Solution::moveZeroes(vector<int>& nums)
{
	int cur = 0;
	for (auto&num : nums)
	{
		if (num != 0)
		{
			nums[cur++] = num;
		}
	}
	while (cur < nums.size())
	{
		nums[cur++] = 0;
	}
}