//给定一个整数数组 arr，如果它是有效的山脉数组就返回 true，否则返回 false。
//
//让我们回顾一下，如果 arr 满足下述条件，那么它是一个山脉数组：
//
//arr.length >= 3
//在 0 < i < arr.length - 1 条件下，存在 i 使得：
//	arr[0] < arr[1] < ... arr[i - 1] < arr[i]
//	arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

#include"leetcode.h"
using namespace std;
bool Solution::validMountainArray(vector<int>& arr)
{
	int asc = 1;
	int dec = 1;
	int n = arr.size();
	if (n < 3)
		return false;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[i - 1])
		{
			if (dec != 1)
				return false;
			asc++;

		}
		if (arr[i] < arr[i - 1])
		{
			if (asc == 1)
				return false;
			dec++;
		}
	}
	if (dec == 1)
		return false;
	return asc + dec - 1 == n;
}