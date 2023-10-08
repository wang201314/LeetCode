//����һ���������� arr�����������Ч��ɽ������ͷ��� true�����򷵻� false��
//
//�����ǻع�һ�£���� arr ����������������ô����һ��ɽ�����飺
//
//arr.length >= 3
//�� 0 < i < arr.length - 1 �����£����� i ʹ�ã�
//	arr[0] < arr[1] < ... arr[i - 1] < arr[i]
//	arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

#include"leetcode.h"
using namespace std;
bool Solution::validMountainArray(vector<int>& arr)
{
	int asc = 1;
	int dec = 1;
	int n = arr.size();
	if (n < 3)
		return false;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[i - 1])
		{
			if (dec != 1)
				return false;
			asc++;

		}
		if (arr[i] < arr[i - 1])
		{
			if (asc == 1)
				return false;
			dec++;
		}
	}
	if (dec == 1)
		return false;
	return asc + dec - 1 == n;
}