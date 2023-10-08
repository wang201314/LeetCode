//�ֵ� wordList �дӵ��� beginWord �� endWord �� ת������ ��һ������������γɵ����� beginWord->s1->s2 -> ...->sk��
//
//ÿһ�����ڵĵ���ֻ��һ����ĸ��
//���� 1 <= i <= k ʱ��ÿ�� si ���� wordList �С�ע�⣬ beginWord ����Ҫ�� wordList �С�
//sk == endWord
//������������ beginWord �� endWord ��һ���ֵ� wordList ������ �� beginWord �� endWord �� ���ת������ �е� ������Ŀ �����������������ת�����У����� 0 ��

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