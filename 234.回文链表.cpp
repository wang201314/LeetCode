//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

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

	// 找到前半部分链表的尾节点并反转后半部分链表
	ListNode* firstHalfEnd = endOfFirstHalf(head);
	ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

	// 判断是否回文
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

	// 还原链表并返回结果
	firstHalfEnd->next = reverseList(secondHalfStart);
	return result;
	}

#endif