//132. �ָ���Ĵ� II
//����һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��ġ�
//���ط���Ҫ��� ���ٷָ���� ��
//ʾ�� 1��
//���룺s = "aab"
//�����1
//���ͣ�ֻ��һ�ηָ�Ϳɽ� s �ָ��["aa", "b"] �������������Ӵ���
//ʾ�� 2��
//���룺s = "a"
//�����0
//ʾ�� 3��
//���룺s = "ab"
//�����1
//��ʾ��
//1 <= s.length <= 2000
//s ����СдӢ����ĸ���
#include"leetcode.h"
using namespace std;
static vector<string>vec;
static vector<vector<bool>>dp;
static size_t ans = INT_MAX;
static void dfs(const string& str, int start)
{
	if (start >= str.length())
	{
		ans = min(ans, vec.size());
		return;
	}
	for (int i = 1; i + start <= str.length(); i++)
	{
		if (dp[start][i + start - 1])
		{
			vec.push_back(str.substr(start, i));
			dfs(str, start + i);
			vec.pop_back();
		}
	}
}
int Solution::minCut(string s) {
	int n = s.size();
	dp.resize(n, vector<bool>(n, true));
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
		}
	}
	dfs(s, 0);
	return ans - 1;
}
class Solution1 {
public:
	int minCut(string s) {
		int n = s.size();
		vector<int>vec(n,INT_MAX);
		vector<vector<bool>>dp(n, vector<bool>(n, true));
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = i + 1; j < n; j++)
			{
				dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (dp[0][i])
				vec[i] = 0;
			else
			{
				for (int j = 0; j < i; j++)
					if(dp[j+1][i])
						vec[i] = min(vec[i],vec[j] + 1);
			}
		}
		return vec[n-1];
	}
};