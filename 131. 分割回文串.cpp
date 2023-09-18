//131. 分割回文串
//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
//回文串 是正着读和反着读都一样的字符串。
//示例 1：
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
//示例 2：
//输入：s = "a"
//输出：[["a"]]
//提示：
//1 <= s.length <= 16
//s 仅由小写英文字母组成
#include<iostream>
#include<vector>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<vector<string>>ans;
	vector<string>vec;
	bool check(const string& s)
	{
		if (s.length() == 1)
			return true;
		int l = 0, r = s.length() - 1;
		while (l <= r)
		{
			if (s[l++] != s[r--])
			{
				return false;
			}
		}
		return true;
	}
	void dfs(const string& str, int start)
	{
		cout << start << endl;
		if (start >= str.length())
		{
			ans.push_back(vec);
			//vec.clear();
			return;
		}
		for (int i = 1; i + start <= str.length(); i++)
		{
			string s = str.substr(start, i);
			if (check(s))
			{
				vec.push_back(s);
				dfs(str, start + i);
				 vec.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s) {
		dfs(s, 0);
		return ans;
	}
};
int main()
{
	Solution s;
	vector<vector<string>>ans=s.partition("cdd");
	for each (auto var in ans)
	{
		for each (auto v in var)
		{
			cout << v << " ";
		};
		cout << endl;
	};
	return 0;
}