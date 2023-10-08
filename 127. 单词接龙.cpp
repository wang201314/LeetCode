//�ֵ� wordList �дӵ��� beginWord �� endWord �� ת������ ��һ������������γɵ����� beginWord->s1->s2 -> ...->sk��
//
//ÿһ�����ڵĵ���ֻ��һ����ĸ��
//���� 1 <= i <= k ʱ��ÿ�� si ���� wordList �С�ע�⣬ beginWord ����Ҫ�� wordList �С�
//sk == endWord
//������������ beginWord �� endWord ��һ���ֵ� wordList ������ �� beginWord �� endWord �� ���ת������ �е� ������Ŀ �����������������ת�����У����� 0 ��

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
