//�� n �����䣬���䰴�� 0 �� n - 1 ��š�������� 0 �ŷ�������������з��䶼����ס�����Ŀ���ǽ������еķ��䡣Ȼ�����㲻����û�л��Կ�׵�ʱ�������ס�ķ��䡣
//
//�������һ�����䣬����ܻ��������ҵ�һ�ײ�ͬ��Կ�ף�ÿ��Կ���϶��ж�Ӧ�ķ���ţ�����ʾԿ�׿��Դ򿪵ķ��䡣�������������Կ��ȥ�����������䡣
//
//����һ������ rooms ���� rooms[i] ������� i �ŷ�����Ի�õ�Կ�׼��ϡ�����ܽ��� ���� ���䷵�� true�����򷵻� false��
#include"leetcode.h"

using namespace std;

bool Solution::canVisitAllRooms(vector<vector<int>>& rooms) {
	unordered_set<int>set;
	queue<int>que;
	que.push(0);
	while (!que.empty())
	{
		int cur = que.front();
		set.insert(cur);
		que.pop();
		for (auto it : rooms[cur])
		{
			if (!set.count(it))
			{
				que.push(it);
			}
		}
	}
	return set.size() == rooms.size();
}