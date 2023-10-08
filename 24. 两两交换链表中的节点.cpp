//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

#include"leetcode.h"

using namespace std;
#if 1
ListNode* Solution::swapPairs(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode*newhead = new ListNode(-1, head);
	ListNode*cur = newhead;
	while (cur->next&&cur->next->next)
	{
		ListNode*next1 = cur->next;
		ListNode*next2 = cur->next->next;
		cur->next = next2;
		next1->next = next2->next;
		next2->next = next1;
		cur = next1;
	}
	return newhead->next;
}
#elif 1
ListNode* Solution::swapPairs(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode*newhead = head->next;
	ListNode*next = newhead->next;
	newhead->next = head;
	head->next = swapPairs(next);
	return newhead;
}
#endif