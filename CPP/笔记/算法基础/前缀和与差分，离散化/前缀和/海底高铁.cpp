#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
ll d[N], t[N];//d[N]是差分数组，t[N]用来记录d[N]的前缀和

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ll n, m; cin >> n >> m;

	ll l; cin >> l;
	for (int i = 1; i < m; i++)//差分的修改是左闭右开的，右端点r刚好在路段的下一个，即开区间点
	{
		int r; cin >> r;
		if (l > r)d[l]--, d[r]++;//确保小的端点++，大的--
		else d[r]--, d[l]++;
		l = r;
	}

	for (int i = 1; i < n; i++)//对差分数组求和
		t[i] = t[i - 1] + d[i];

	ll a, b, c;
	ll pay = 0;//pay为最小花费
	for (int i = 1; i < n; i++)//从1到n遍历，刚好是n个城市对应的n-1个路段
	{
		cin >> a >> b >> c;
		if (t[i])pay += min(a * t[i], c + b * t[i]);//贪心
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
