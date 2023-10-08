#pragma once
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
#include"ListNode.h"
#include"TreeNode.h"
using std::vector;
using std::string;
class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms);
	int islandPerimeter(vector<vector<int>>& grid);
	int ladderLength(string beginWord, string endWord, vector<string>& wordList);
	vector<vector<string>> partition(string s);
	int minCut(string s);
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights);
	int largestIsland(vector<vector<int>>& grid);
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination);
	vector<int> findRedundantConnection(vector<vector<int>>& edges);
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges);
	vector<int> smallerNumbersThanCurrent(vector<int>& nums);
	bool validMountainArray(vector<int>& arr);
	bool uniqueOccurrences(vector<int>& arr);
	void moveZeroes(vector<int>& nums);
	void rotate(vector<int>& nums, int k);
	int pivotIndex(vector<int>& nums);
	vector<int> searchRange(vector<int>& nums, int target);
	vector<int> sortArrayByParityII(vector<int>& nums);
	int searchInsert(vector<int>& nums, int target);
	ListNode* swapPairs(ListNode* head);
	bool isPalindrome(ListNode* head);
	int totalNQueens(int n); 
	string predictPartyVictory(string senate);
	TreeNode* balanceBST(TreeNode* root);
};