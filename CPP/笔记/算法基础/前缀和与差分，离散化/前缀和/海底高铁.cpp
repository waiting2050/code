#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
ll d[N], t[N];//d[N]�ǲ�����飬t[N]������¼d[N]��ǰ׺��

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ll n, m; cin >> n >> m;

	ll l; cin >> l;
	for (int i = 1; i < m; i++)//��ֵ��޸�������ҿ��ģ��Ҷ˵�r�պ���·�ε���һ�������������
	{
		int r; cin >> r;
		if (l > r)d[l]--, d[r]++;//ȷ��С�Ķ˵�++�����--
		else d[r]--, d[l]++;
		l = r;
	}

	for (int i = 1; i < n; i++)//�Բ���������
		t[i] = t[i - 1] + d[i];

	ll a, b, c;
	ll pay = 0;//payΪ��С����
	for (int i = 1; i < n; i++)//��1��n�������պ���n�����ж�Ӧ��n-1��·��
	{
		cin >> a >> b >> c;
		if (t[i])pay += min(a * t[i], c + b * t[i]);//̰��
	}

	cout << pay;

	return 0;
}
//9 10
//3 1 4 1 5 9 2 6 5 3
//200 100 50
//300 299 100
//500 200 500
//345 234 123
//100 50 100
//600 100 1
//450 400 80
//2 1 10

//6394
