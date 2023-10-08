//字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord->s1->s2 -> ...->sk：
//
//每一对相邻的单词只差一个字母。
//对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
//sk == endWord
//给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。

#include"leetcode.h"
using namespace std;

static unordered_map<string, vector<string>>map;
static unordered_set<string>visited;
static int  bfs(string start, string end)
{
	queue<string>que;
	que.push(start);
	int ans = 1;
	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size; i++)
		{
			string top = que.front();
			if (top == end)
				return ans;
			visited.insert(top);
			que.pop();
			for (auto next : map[top])
			{
				if (!visited.count(next))
					que.push(next);
			}
		}
		ans++;
	}
	return 0;
}
static bool isValue(string a, string b)
{
	int n = a.length();
	int m = b.length();
	if (n > m + 1)
		return false;
	int cnt = 0;
	for (int i = 0; i < min(n, m); i++)
	{
		if (a[i] != b[i])
			cnt++;
	}
	return abs(n - m) + cnt == 1;
}
int Solution::ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	if (beginWord == endWord)
		return 1;
	unordered_set<string>visited(wordList.begin(), wordList.end());
	if (!visited.count(endWord))
		return 0;
	unordered_map<string, int>map;
	map[beginWord] = 1;
	queue<string>que;
	que.push(beginWord);
	while (!que.empty())
	{
		string top = que.front();
		int path = map[top];
		que.pop();
		for (int i = 0; i < top.size(); i++)
		{
			string newnode = top;
			for (char j = 'a'; j <= 'z'; j++)
			{
				newnode[i] = j;

				if (newnode == endWord)
					return path + 1;
				if (visited.count(newnode) && !map[newnode])
				{
					map[newnode] = path + 1;
					que.push(newnode);
				}
			}
		}
	}
	return 0;
}
