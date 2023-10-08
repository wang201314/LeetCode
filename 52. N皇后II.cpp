//n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//
//给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
#include"leetcode.h"

using namespace std;
#if 1
static int ans=0;

static vector<bool>col;
static vector<bool>intersection1; 
static vector<bool>intersection2;
static void dfs(int row,int n)
{
	if (n == row)
	{
		ans++;
		return;
	}
	for (int j = 0; j < n; j++)
	{
		if (col[j]|| intersection1[(j - row) + n]|| intersection2[(j + row)])
			continue;
		else
		{
			col[j] = true;
			intersection1[(j - row) + n] = true;
			intersection2[(j + row)] = true;
			dfs(row + 1, n);
			col[j] = false;
			intersection1[(j - row) + n] = false;
			intersection2[(j + row)] = false;
		}
	}
}
int Solution::totalNQueens(int n)
{
	//vector<vector<bool>>vec(n, vector<bool>(n, false));
	col.resize(n, false);
	intersection1.resize(2*n, false);
	intersection2.resize(2 * n, false);
	dfs(0,n);
	return ans;
}
#elif 0
bool Solution::isPalindrome(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode*slow = head;
	ListNode*fast = head;
	function<ListNode*(ListNode*)>reverse = [](ListNode*root)->ListNode*
	{
		ListNode*cur = root;
		ListNode*pre = nullptr;
		while (cur)
		{
			ListNode*next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	};
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast)
	{
		fast = reverse(slow->next);
	}
	else
		fast = reverse(slow);
	while (fast)
	{
		if (head->val != fast->val)
			return false;
		head = head->next;
		fast = fast->next;
	}
	return true;
}
#elif 0


#endif