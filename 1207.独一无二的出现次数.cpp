//给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
//
//如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。
#include"leetcode.h"
using namespace std;
bool Solution::uniqueOccurrences(vector<int>& arr)
{
	vector<int>hash(2001,0);
	for (auto&num : arr)
	{
		hash[num+1000]++;
	}
	unordered_set<int>set;
	for (auto num : hash)
	{
		if (!num)
			continue;
		if (set.count(num))
		{
			return false;
		}
		set.insert(num);
	}
	return true;
}