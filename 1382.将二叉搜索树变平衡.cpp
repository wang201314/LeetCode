//给你一棵二叉搜索树，请你返回一棵 平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。如果有多种构造方法，请你返回任意一种。
//
//如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。
#include"leetcode.h"

using namespace std;
#if 1

TreeNode* Solution::balanceBST(TreeNode*root)
{
	vector<int>vec;
	function<void(TreeNode*root)>toVec = [&](TreeNode*root)
	{
		if (!root)
			return;
		toVec(root->left);
		vec.push_back(root->val);
		toVec(root->right);
	};
	toVec(root);
	function<TreeNode*(int ,int )>toTree = [&](int l, int r)->TreeNode*
	{
		if (l>r)
			return nullptr;
		int mid = (l + r) / 2;
		TreeNode*node = new TreeNode(vec[mid]);
		node->left = toTree(l,mid-1);
		node->right = toTree(mid+1, r);
		return node;
	};
	return toTree(0, vec.size() - 1);
}
#elif 0
TreeNode* Solution::balanceBST(TreeNode*root)
{
	
}
#elif 0


#endif