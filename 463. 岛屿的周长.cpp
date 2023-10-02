//�� n �����䣬���䰴�� 0 �� n - 1 ��š�������� 0 �ŷ�������������з��䶼����ס�����Ŀ���ǽ������еķ��䡣Ȼ�����㲻����û�л��Կ�׵�ʱ�������ס�ķ��䡣
//
//�������һ�����䣬����ܻ��������ҵ�һ�ײ�ͬ��Կ�ף�ÿ��Կ���϶��ж�Ӧ�ķ���ţ�����ʾԿ�׿��Դ򿪵ķ��䡣�������������Կ��ȥ�����������䡣
//
//����һ������ rooms ���� rooms[i] ������� i �ŷ�����Ի�õ�Կ�׼��ϡ�����ܽ��� ���� ���䷵�� true�����򷵻� false��
#include"leetcode.h"

using namespace std;

extern int dir[4][2];
int Solution::islandPerimeter(vector<vector<int>>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 1)
			{
				for (int i = 0; i < 4; i++)
				{
					int nextx = i + dir[i][0];
					int nexty = j + dir[i][1];
					if (nextx >= n || nextx < 0 || nexty >= m || nexty < 0 || grid[nextx][nexty] == 0)
					{
						ans++;
					}
				}
			}
		}
	}
	return ans;
}