#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <random>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;
ll a[N], stk[N], l[N], r[N], top;//l储存a[i]左边元素下标，r右边

void solve()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	//i=1,找a[i]的左边
	for (int i = 1; i <= n; i++)
	{
		while (top && a[stk[top]] >= a[i]) top--;//寻找左边第一个<a[i]的元素

		if (!top) l[i] = 0;//如果没有，就让l[i]=0（比如i=1,那么i-0=1,也就是说每一个元素默认自己是占左边一个位置的）
		else l[i] = stk[top];//如果有，就记录它的下标

		stk[++top] = i;//把元素压入栈
	}

	top = 0;
	for (int i = n; i >= 1; i--)//i=n，遍历a[i]的右边元素
	{
		while (top && a[stk[top]] > a[i]) top--;//寻找右边第一个<=a[i]的元素

		if (!top) r[i] = n + 1;//同样的，每个元素也占右边一个位置
		else r[i] = stk[top];

		stk[++top] = i;
	}

	ll sum = 0;
	for (int i = 1; i <= n; i++) sum += a[i] * (i - l[i]) * (r[i] - i);

	cout << sum;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//5
//7 8 5 6 7
//
//86
