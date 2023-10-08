//����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣������ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻������

#include"leetcode.h"

using namespace std;
#if 0
bool Solution::isPalindrome(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return true;
	vector<int>vec;
	while (head)
	{
		vec.push_back(head->val);
		head = head->next;
	}
	int l = 0;
	int r = vec.size() - 1;
	while (l <= r)
	{
		if (vec[l++] != vec[r--])
			return false;
	}
	return true;
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
		fast=reverse(slow->next);
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
#elif 1

static ListNode* reverseList(ListNode* head) {
	ListNode* prev = nullptr;
	ListNode* curr = head;
	while (curr != nullptr) {
		ListNode* nextTemp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextTemp;
	}
	return prev;
}

static ListNode* endOfFirstHalf(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast->next != nullptr && fast->next->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
bool Solution::isPalindrome(ListNode* head) {
	if (head == nullptr) {
		return true;
	}

	// �ҵ�ǰ�벿�������β�ڵ㲢��ת��벿������
	ListNode* firstHalfEnd = endOfFirstHalf(head);
	ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

	// �ж��Ƿ����
	ListNode* p1 = head;
	ListNode* p2 = secondHalfStart;
	bool result = true;
	while (result && p2 != nullptr) {
		if (p1->val != p2->val) {
			result = false;
		}
		p1 = p1->next;
		p2 = p2->next;
	}

	// ��ԭ�������ؽ��
	firstHalfEnd->next = reverseList(secondHalfStart);
	return result;
	}

#endif