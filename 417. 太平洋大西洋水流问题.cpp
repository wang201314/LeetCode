//��һ�� m �� n �ľ��ε��죬�� ̫ƽ�� �� ������ ���ڡ� ��̫ƽ�� ���ڴ�½����߽���ϱ߽磬�� �������� ���ڴ�½���ұ߽���±߽硣
//��������ָ��һ�������ɷ��ε�Ԫ����ɵ����񡣸���һ�� m x n ���������� heights �� heights[r][c] ��ʾ����(r, c) �ϵ�Ԫ�� ���ں�ƽ��ĸ߶� ��
//������ˮ�϶࣬������ڵ�Ԫ��ĸ߶� С�ڻ���� ��ǰ��Ԫ��ĸ߶ȣ���ˮ����ֱ���򱱡��ϡ��������������ڵ�Ԫ��ˮ���ԴӺ��󸽽����κε�Ԫ�����뺣��
//������������ result �� 2D �б� ������ result[i] = [ri, ci] ��ʾ��ˮ�ӵ�Ԫ��(ri, ci) ���� �ȿ�����̫ƽ��Ҳ����������� ��
//ʾ�� 1��
//���� : heights = [[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]
//��� : [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]]
//ʾ�� 2��
//���� : heights = [[2, 1], [1, 2]]
//��� : [[0, 0], [0, 1], [1, 0], [1, 1]]
//��ʾ��
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