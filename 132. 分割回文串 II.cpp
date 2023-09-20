//132. 分割回文串 II
//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
//返回符合要求的 最少分割次数 。
//示例 1：
//输入：s = "aab"
//输出：1
//解释：只需一次分割就可将 s 分割成["aa", "b"] 这样两个回文子串。
//示例 2：
//输入：s = "a"
//输出：0
//示例 3：
//输入：s = "ab"
//输出：1
//提示：
//1 <= s.length <= 2000
//s 仅由小写英文字母组成
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<string>vec;
	vector<vector<bool>>dp;
	size_t ans = INT_MAX;
	void dfs(const string& str, int start)
	{
		if (start >= str.length())
		{
			ans=min(ans,vec.size());
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
	int minCut(string s) {
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
		return ans-1;
	}
};
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

int main()
{
	Solution1 s;
	cout << s.minCut("cdd")<<endl;	
	int a;
	cin >> a;
	return 0;
}