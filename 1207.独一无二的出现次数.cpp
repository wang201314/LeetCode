//����һ���������� arr�������æͳ��������ÿ�����ĳ��ִ�����
//
//���ÿ�����ĳ��ִ������Ƕ�һ�޶��ģ��ͷ��� true�����򷵻� false��
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