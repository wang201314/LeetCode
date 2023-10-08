#include"leetcode.h"
#include<iostream>
using namespace std;
//char*test()
//{
//	char *p = "heelo";
//	p[1] = 'a';
//	return p;
//}
int main()
{
	Solution s;
	vector<int>vec{ 
		1,null,2,null,3,null,4
	};
	Linked_List LL(vec);

	Binary_Tree BT(vec);
	BT.printTree(BT.root);
	//cout<<s.totalNQueens(3);
	/*for (auto it : vec)
	{
		cout << it << " ";
	}*/
	//char*p = test();
	//printf("%s",p);
	int a;
	cin >> a;
}