//��Ŀ����
//�����һ����ʵ�����ֲ�ͬ����֮�������ת����
//
//�����ʽ
//�����У���һ����һ������������ʾ��Ҫת�������Ľ��� n (2��n��16)���ڶ�����һ�� n ��������
//�� n>10 ���ô�д��ĸ A��F ��ʾ���� 10��15�����Ҹ� n ��������Ӧ��ʮ���Ƶ�ֵ������ 10^9
// ��������Ҳ��һ������������ʾת��֮������Ľ��� m (2��m��16)��
//
//�����ʽ
//һ������������ʾת��֮��� m ��������

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const string cri = "0123456789ABCDEF";

int ntoten(int n, string num)
{
	int res = 0;
	for(int i = 0; i < num.size(); i++)
	{
		if(num[i] >= '0' && num[i] <= '9')
			res = res * n + num[i] - '0';
		else res = res * n + num[i] - 'A' + 10;
	}
	
	return res;
}

string tentom(int num, int m)
{
	string res;
	while(num)
	{
		res = cri[num % m] + res;
		num /= m;
	}
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m;
	string num;
	
	cin >> n >> num >> m;
	
	cout << tentom(ntoten(n, num), m);
	
	return 0;
}

//16
//FF
//2
//
//11111111
