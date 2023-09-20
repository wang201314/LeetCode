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
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
	void dfs(vector<vector<int>>& heights, vector<vector<bool>>&visited, int row, int col)
	{
		//row<0||row>=heights.size()||col<0||col>=heights[0].size()||
		if (visited[row][col])
			return;
		visited[row][col] = true;
		for (int i = 0; i < 4; i++)
		{
			int newr = row + dir[i][0];
			int newc = col + dir[i][1];
			if (newr < 0 || newr >= heights.size() || newc < 0 || newc >= heights[0].size() || heights[newr][newc] < heights[row][col])
			{
				continue;
			}
			dfs(heights, visited, newr, newc);
		}
	}
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		vector<vector<int>>ans;
		int row = heights.size();
		int col = heights[0].size();
		vector<vector<bool>>visited(row, vector<bool>(col, false));
		vector<vector<bool>>visited1(row, vector<bool>(col, false));

		for (int i = 0; i < col; i++)
		{
			dfs(heights, visited, 0, i);
			dfs(heights, visited1, row - 1, i);
		}
		for (int i = 0; i < row; i++)
		{
			dfs(heights, visited, i, 0);
			dfs(heights, visited1, i, col - 1);
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
};
class Solution1 {
public:
	int minCut(string s) {
		int n = s.size();
		vector<int>vec(n, INT_MAX);
		vector<vector<bool>>dp(n, vector<bool>(n, true));
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = i + 1; j < n; j++)
			{
				dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (dp[0][i])
				vec[i] = 0;
			else
			{
				for (int j = 0; j < i; j++)
					if (dp[j + 1][i])
						vec[i] = min(vec[i], vec[j] + 1);
			}
		}
		return vec[n - 1];
	}
};

int main()
{
	Solution s;
	vector<vector<int>>heights{ {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4} };
	vector<vector<int>>ans = s.pacificAtlantic(heights);

	for each (auto var in ans)
	{
		for each (auto v in var)
		{
			cout << v << " ";
		};
		cout << endl;
	};
	int a;
	cin >> a;
	return 0;
}