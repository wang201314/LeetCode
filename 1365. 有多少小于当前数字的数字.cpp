//字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord->s1->s2 -> ...->sk：
//
//每一对相邻的单词只差一个字母。
//对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
//sk == endWord
//给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。

#include"leetcode.h"
using namespace std;
vector<int> Solution::smallerNumbersThanCurrent(vector<int>& nums) {
	int n = nums.size();
	vector<pair<int, int>>vec(n, { 0,0 });
	for (int i = 0; i < n; i++)
	{
		vec[i] = { nums[i],i };
	}
	sort(vec.begin(), vec.end());
	nums[vec[0].second] = 0;
	for (int i = 1; i < n; i++)
	{
		nums[vec[i].second] = vec[i].first == vec[i - 1].first?nums[vec[i - 1].second] :i;
	}
	return nums;
}