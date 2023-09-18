//131. �ָ���Ĵ�
//����һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����� ���Ĵ� ������ s ���п��ܵķָ����
//���Ĵ� �����Ŷ��ͷ��Ŷ���һ�����ַ�����
//ʾ�� 1��
//���룺s = "aab"
//�����[["a","a","b"],["aa","b"]]
//ʾ�� 2��
//���룺s = "a"
//�����[["a"]]
//��ʾ��
//1 <= s.length <= 16
//s ����СдӢ����ĸ���
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