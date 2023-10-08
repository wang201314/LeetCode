//����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣������ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻������

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