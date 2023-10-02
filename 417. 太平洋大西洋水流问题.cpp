//有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。
//这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标(r, c) 上单元格 高于海平面的高度 。
//岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。
//返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格(ri, ci) 流动 既可流向太平洋也可流向大西洋 。
//示例 1：
//输入 : heights = [[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]
//输出 : [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]]
//示例 2：
//输入 : heights = [[2, 1], [1, 2]]
//输出 : [[0, 0], [0, 1], [1, 0], [1, 1]]
//提示：
//	m == heights.length
//	n == heights[r].length
//	1 <= m, n <= 200
//	0 <= heights[r][c] <= 105
#include"leetcode.h"
using namespace std;
extern int dir[4][2];
static void dfs(vector<vector<int>>& heights, vector<vector<bool>>&visited, int row, int col)
{
	//row<0||row>=heights.size()||col<0||col>=heights[0].size()||
	if (visited[row][col])
		return;
	visited[row][col] = true;
	for (int i = 0; i < 4; i++)
	{
		int newr = row + dir[i][0];
		int newc = col + dir[i][1];
		if (newr < 0 || newr >= heights.size() || newc < 0 || newc >= heights[0].size() || visited[newr][newc] || heights[newr][newc] < heights[row][col])
		{
			continue;
		}
		dfs(heights, visited, newr, newc);
	}
}
static void bfs(vector<vector<int>>& heights, vector<vector<bool>>&visited, int row, int col)
{
	if (visited[row][col])
		return;
	visited[row][col] = true;
	queue<pair<int, int>>que;
	que.push({ row,col });
	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size; i++)
		{
			int cr = que.front().first;
			int cc = que.front().second;

			que.pop();
			for (int j = 0; j < 4; j++)
			{
				int newr = cr + dir[j][0];
				int newc = cc + dir[j][1];
				if (newr < 0 || newr >= heights.size() || newc < 0 || newc >= heights[0].size() || visited[newr][newc] || heights[newr][newc] < heights[cr][cc])
					continue;
				visited[newr][newc] = true;
				que.push({ newr,newc });
			}
		}
	}
}
static void search(void(*f)(vector<vector<int>>& heights, vector<vector<bool>>&visited, int row, int col), vector<vector<int>>& heights, vector<vector<bool>>&visited, int row, int col)
{
	(*f)(heights, visited, row, col);
}
vector<vector<int>> Solution::pacificAtlantic(vector<vector<int>>& heights) {
	vector<vector<int>>ans;
	int row = heights.size();
	int col = heights[0].size();
	vector<vector<bool>>visited(row, vector<bool>(col, false));
	vector<vector<bool>>visited1(row, vector<bool>(col, false));
	using MemberFunctionPtr = void (*)(vector<vector<int>>&, vector<vector<bool>>&, int, int);
	MemberFunctionPtr f = &bfs;
	for (int i = 0; i < col; i++)
	{
		(*f)(heights, visited, 0, i);
		(*f)(heights, visited1, row - 1, i);
		//dfs(heights, visited, 0, i);
		//dfs(heights, visited1, row - 1, i);
	}
	for (int i = 0; i < row; i++)
	{
		/*search(&Solution::dfs, heights, visited, i, 0);
		search(&Solution::dfs, heights, visited1, i, col-1);*/
		(*f)(heights, visited, i, 0);
		(*f)(heights, visited1, i, col - 1);
		//dfs(heights, visited, i, 0);
		//dfs(heights, visited1, i, col - 1);
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (visited[i][j] && visited1[i][j])
			{
				ans.push_back({ i,j });
			}
		}
	}
	return ans;
}