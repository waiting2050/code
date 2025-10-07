#include <iostream>
#include <cstdio>
#include <string>
#include <climits>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <random>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
int n, q;
ll a[N], t[N];//a用于输入，同时单点修改。t表示一段长度为lowbit区间的和。

int lowbit(int x) { return x & -x; }//lowbit用于取得长度，这个长度是根据二进制来的，不是线性的 

void update(int k, ll x)//用于更新t数组,从k开始的直到n为止全部t数组加上x
{
	for (int i = k; i <= n; i += lowbit(i)) t[i] += x;//注意这里更新是通过加lowbit长 
}

ll getsum(ll x)//类似于求前缀和
{
	ll res = 0;				//注意这里求和用的是-lowbit长 
	for (int i = x; i > 0; i -= lowbit(i)) res += t[i];//通过-lowbit实现求和
	return res;
}

void solve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) update(i, a[i]);

	while (q--)
	{
		int op; cin >> op;
		if (op == 1)
		{
			ll k, v; cin >> k >> v;
			update(k, v);
		}
		else
		{
			ll l, r; cin >> l >> r;
			cout << getsum(r) - getsum(l - 1) << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//5 4
//1 2 3 4 5
//1 1 1
//2 1 2
//1 4 2
//2 3 4
//
//4
//9
