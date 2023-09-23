//给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
//
//返回执行此操作后，grid 中最大的岛屿面积是多少？
//
//岛屿 由一组上、下、左、右四个方向相连的 1 形成。
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:

	int n;
	int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
	int count;
	void dfs(vector<vector<int>>&grid, vector<vector<int>>&tag, int row, int col, int t)
	{
		if (tag[row][col] == t)
			return;
		tag[row][col] = t;
		count++;
		for (int i = 0; i < 4; i++)
		{
			int newr = row + dir[i][0];
			int newc = col + dir[i][1];
			if (newr < 0 || newr >= n || newc < 0 || newc >= n || tag[newr][newc] == t || grid[newr][newc] == 0)
				continue;
			dfs(grid, tag, newr, newc, t);
		}
	}
	int largestIsland(vector<vector<int>>& grid) {
		int ans = 1;
		n = grid.size();
		vector<vector<int>>tag(n, vector<int>(n, -1));
		unordered_map<int, int>area;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] && tag[i][j] == -1)
				{
					int t = i * n + j;
					count = 0;
					dfs(grid, tag, i, j, t);
					area[t] = count;
					ans = max(ans, count);
				}
			}

		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 0)
				{
					int temp = 1;
					unordered_set<int>set;
					for (int k = 0; k < 4; k++)
					{
						int newr = i + dir[k][0];
						int newc = j + dir[k][1];
						if (newr < 0 || newr >= n || newc < 0 || newc >= n || set.count(tag[newr][newc]) || grid[newr][newc] == 0)
						{
							continue;
						}
						set.insert(tag[newr][newc]);
						temp += area[tag[newr][newc]];
					}
					ans = max(temp, ans);
				}
			}

		}
		return ans;
	}
};

int main()
{
	Solution s;
	vector<vector<int>>heights{ {1,0},{1,0} };
	cout << s.largestIsland(heights);

	int a;
	cin >> a;
	return 0;
}