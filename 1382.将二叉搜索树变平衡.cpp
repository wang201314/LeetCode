//����һ�ö��������������㷵��һ�� ƽ��� �Ķ����������������ɵ���Ӧ����ԭ������������ͬ�Ľڵ�ֵ������ж��ֹ��췽�������㷵������һ�֡�
//
//���һ�ö����������У�ÿ���ڵ�����������߶Ȳ���� 1 �����Ǿͳ���ö����������� ƽ��� ��
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