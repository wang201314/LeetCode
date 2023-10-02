#pragma once
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<vector>
#include<string>
class Solution {
public:
	bool canVisitAllRooms(std::vector<std::vector<int>>& rooms);
	int islandPerimeter(std::vector<std::vector<int>>& grid);
	int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList);
	std::vector<std::vector<std::string>> partition(std::string s);
	int minCut(std::string s);
	std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights);
	int largestIsland(std::vector<std::vector<int>>& grid);
};