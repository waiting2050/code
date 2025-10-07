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
ll a[N], td[N], tid[N];//td[]和tid都是差分，但是由于是树状的，会与连续的差分数组在访问时有区别

int lowbit(int x) { return x & -x; }//lowbit会取得一个长度，虽然数组下标是连续的，但是数组下标的更新是以lowbit为单位长的。

void update(int k, ll x)//更新树状数组
{
	for (int i = k; i <= n; i += lowbit(i)) td[i] += x, tid[i] += k * x;//k是下标
}//为什么是k*x不是i*x,因为这里需要给从k开始到n的数组都进行k*x的修改，每个修改是一样的。
//（因为树状的差分数组是有包含关系的，所以对子节点修改完以后，也要对父节点修改。）

ll getsum(ll x)//对区间的查询
{
	ll res = 0;
	for (int i = x; i > 0; i -= lowbit(i)) res += (x + 1) * td[i] - tid[i];//根据公式得到的
	return res;
}

void solve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) update(i, a[i]), update(i+1, -a[i]);//对差分数组td, tid的更新，差分的性质是一样的

	while (q--)
	{
		int op; cin >> op;
		if (op == 1)
		{
			ll l, r, v; cin >> l >> r >> v;
			update(l, v), update(r + 1, -v);
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
//1 1 3 1
//2 1 2
//1 4 5 2
//2 3 4
//
//5
//10
