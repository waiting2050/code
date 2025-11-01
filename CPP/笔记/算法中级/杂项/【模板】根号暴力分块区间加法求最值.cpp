// 要找某区间小于x的某个数，一样是分成三块处理，对于1,3部分，可以单独处理每个元素，找到有多少个元素加上add标记后<target
// 对于第2部分，二分查找第一个大于等于target的元素的前一个元素即可，注意有add标记，所以a[i]+add[blk[i]]<x => a[i] < x - add[blk[i]]
// 单独处理部分的更新逻辑和查询逻辑是一样的，代码直接cv即可；注意成块时要更新add，查询时add都有出现

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 1e5 + 7;

vector<ll> v[N];
ll a[N], blk[N], L[N], R[N], add[N];

void resort(int idx) // 注意resort只有在不成块时调用
{
	v[idx].clear();
	for(int i = L[idx]; i <= R[idx]; i++) v[idx].pb(a[i]);
	sort(v[idx].begin(), v[idx].end());
}

void Add(int l, int r, ll x)
{
	if(blk[l] == blk[r])
	{
		for(int i = l; i <= r; i++) a[i] += x;
		resort(blk[l]);
		return;
	}
	
	for(int i = l; i <= R[blk[l]]; i++) a[i] += x;
	resort(blk[l]);
	
	for(int i = blk[l] + 1; i < blk[r]; i++) add[i] += x;
	
	for(int i = L[blk[r]]; i <= r; i++) a[i] += x;
	resort(blk[r]);
}

ll query(int l, int r, ll x)
{
	int res = 0;
	if(blk[l] == blk[r])
	{
		for(int i = l; i <= r; i++) res += a[i] + add[blk[i]] < x;
		return res;
	}
	// 1部分
	for(int i = l; i <= R[blk[l]]; i++) res += a[i] + add[blk[i]] < x;

    // 2部分  注意这里查找的数要减去标记
	for(int i = blk[l] + 1; i < blk[r]; i++) res += lower_bound(v[i].begin(), v[i].end(), x - add[i]) - v[i].begin();

    // 3部分
	for(int i = L[blk[r]]; i <= r; i++) res += a[i] + add[blk[i]] < x;
	
	return res;
}

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int sz = sqrt(n) + 1;
	for(int i = 1; i <= n; i++)
	{
		blk[i] = i / sz + 1;
		if(i > 1 && blk[i - 1] != blk[i]) L[blk[i]] = i, R[blk[i - 1]] = i - 1;
	}
	L[blk[1]] = 1, R[blk[n]] = n;
	for(int i = blk[1]; i <= blk[n]; i++) resort(i);
	
	int q; cin >> q;
	while(q--)
	{
		ll op, l, r, x; cin >> op >> l >> r >> x;
		if(op == 1) Add(l, r, x);
		else cout << query(l, r, x) << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 5
// 1 2 3 4 5
// 4
// 2 1 3 2
// 2 2 4 4
// 1 3 3 2
// 2 1 5 5

// 1
// 2
// 3