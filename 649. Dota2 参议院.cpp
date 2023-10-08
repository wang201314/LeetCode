//Dota2 ����������������Ӫ��Radiant����ԣ��� Dire��ҹ�ʣ�
//
//Dota2 ����Ժ���������ɵĲ���Ա��ɡ����ڲ���Ժϣ����һ�� Dota2 ��Ϸ��ĸı�����������������һ��������Ϊ���̵�ͶƱ���С���ÿһ���У�ÿһλ����Ա��������ʹ����Ȩ���е� һ �
//
//��ֹһ������Ա��Ȩ��������Ա��������һλ����Ա����һ�ֺ����ļ�����ɥʧ ���е�Ȩ�� ��
//����ʤ�����������Ա������Ȩ��ͶƱ�Ĳ���Ա���� ͬһ����Ӫ�� ������������ʤ������������Ϸ�е��йر仯��
//����һ���ַ��� senate ����ÿ������Ա����Ӫ����ĸ 'R' �� 'D'�ֱ������ Radiant����ԣ��� Dire��ҹ�ʣ���Ȼ������� n ������Ա�������ַ����Ĵ�С���� n��
//
//����Ϊ�����Ĺ��̴Ӹ���˳��ĵ�һ������Ա��ʼ�����һ������Ա��������һ���̽�������ͶƱ����������ʧȥȨ���Ĳ���Ա���ڹ����б�������
//
//����ÿһλ����Ա���㹻��������Ϊ�Լ�������������õĲ��ԣ�����ҪԤ����һ�����ջ�����ʤ������ Dota2 ��Ϸ�о����ı䡣���Ӧ���� "Radiant" �� "Dire" ��
#include"leetcode.h"

using namespace std;
#if 0

string Solution::predictPartyVictory(string senate)
{
	queue<int>R,S;
	int n = senate.size();
	for (int i = 0;i< n; i++)
	{
		if (senate[i] == 'R')
			R.push(i);
		else
			S.push(i);
	}
	while (!R.empty()&&!S.empty())
	{
		if (R.front() < S.front())
		{
			R.push(R.front()+n);
		}
		else
		{
			S.push(S.front() + n);
		}
		R.pop();
		S.pop();
	}
	return R.empty()?"Dire":"Radiant";
}
#elif 1
string Solution::predictPartyVictory(string senate)
{
	int Rcount = 0;
	bool R = true,D = true;
	while (D&&R)
	{
		R = false;
		D = false;
		for (auto&it : senate)
		{
			if (it == 'R')
			{
				if (Rcount < 0)
					it = '*';
				else
					R = true;
				Rcount++;
			}
			else if (it == 'D')
			{
				if (Rcount > 0)
					it = '*';
				else
					D = true;
				Rcount--;
			}
		}
	}
	return D? "Dire" : "Radiant";
}
#elif 0


#endif