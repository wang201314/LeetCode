#pragma once
#include<vector>
#include<iostream>
#include<queue>
#define null NULL
struct TreeNode
{
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Binary_Tree
{
public:
	TreeNode*root;
	Binary_Tree(std::vector<int>& values) {
		if (values.empty()) return;

		root = new TreeNode(values[0]);
		std::queue<TreeNode*> nodes;
		nodes.push(root);

		for (int i = 1; i < values.size(); i++) {
			TreeNode* current = nodes.front();
			nodes.pop();

			if (values[i] != null) {
				current->left = new TreeNode(values[i]);
				nodes.push(current->left);
			}

			i++;
			if (i < values.size() && values[i] != null) {
				current->right = new TreeNode(values[i]);
				nodes.push(current->right);
			}
		}
	}

	// 打印二叉树（使用层序遍历）
	void printTree(TreeNode* root) {
		if (!root) return;
		std::queue<TreeNode*> nodes;
		nodes.push(root);

		while (!nodes.empty()) {
			TreeNode* current = nodes.front();
			nodes.pop();
			if (current) {
				std::cout << current->val << " ";
				nodes.push(current->left);
				nodes.push(current->right);
			}
			else {
				std::cout << "null ";
			}
		}
	}
	
};