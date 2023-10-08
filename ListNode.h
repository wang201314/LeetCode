#pragma once
#include<vector>
#include<iostream>
struct ListNode
{
	int val;
	ListNode*next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Linked_List
{
public:
	ListNode*head;
	Linked_List(std::vector<int>vec)
	{
		size_t n = vec.size();
		if (n == 0)
			return;
		head = new ListNode(vec[0]);
		ListNode*pre = head;
		for (int i = 1; i < n; i++)
		{
			ListNode*next = new ListNode(vec[i]);
			pre->next = next;
			pre = pre->next;
		}
	}
	void print()
	{
		ListNode*pre = head;
		while (pre)
		{
			std::cout << pre->val<<" ";
			pre = pre->next;
		}
	}
};