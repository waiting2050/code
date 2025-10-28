// 将所有数分为大小为√n+1的若干块，对某个区间的操作分为2种情况：
//    1.区间被某个单位区间包含，单独对这个区间的每个数做操作，复杂度<=O(√n)
//    2.区间横跨多个单位区间，将该区间分为三部分，头尾是单位区间的子集，分别单独操作；中间是多个单位区间拼成，对单位区间操作即可
// 这样头+尾<=O(√n)，中间<O(√n)，每次查询或更新是O(√n)的

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 1e5 + 7;

ll a[N]; // a是最小单元，原始数组
ll add[N]; // add类似于懒标记，记录区间的更新
ll sum[N]; // sum是单位区间的区间和
ll blk[N]; // blk是分块后的编号
ll L[N], R[N]; // 分别记录某个单位区间的左右端点下标

// 首先对单独的不成块的区间更新肯定需要a数组；但是a数组对成块的区间更新没用
// 只要更新必然会修改区间和，所以sum在ADD里一定出现；但是查询时只有成块的情况才用的到它
// add是标记某个区间更新了多少，只有区间更新才用得到；在查询时，区间信息由sum直接得到，add只在不成块时用到

void Add(ll l, ll r, ll x)
{
	if(blk[l] == blk[r])
	{
		for(ll i = l; i <= r; i++)
		{
			a[i] += x;
			sum[blk[i]] += x;
		}
		return;
	}
	
	for(ll i = l; i <= R[blk[l]]; i++) a[i] += x, sum[blk[i]] += x;
	for(ll i = blk[l] + 1; i < blk[r]; i++) add[i] += x, sum[i] += (R[i] - L[i] + 1) * x;
	for(ll i = L[blk[r]]; i <= r; i++) a[i] += x, sum[blk[i]] += x;
}

ll query(ll l, ll r)
{
	ll res = 0;
	if(blk[l] == blk[r])
	{
		for(ll i = l; i <= r; i++) res += a[i] + add[blk[i]];
		return res;
	}
	
	for(ll i = l; i <= R[blk[l]]; i++) res += a[i] + add[blk[i]];
	for(ll i = blk[l] + 1; i < blk[r]; i++) res += sum[i];
	for(ll i = L[blk[r]]; i <= r; i++) res += a[i] + add[blk[i]];
	
	return res;
}

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int sz = sqrt(n) + 1; // 防止n为0
	for(int i = 1; i <= n; i++)
	{
		blk[i] = i / sz + 1; // 获取编号
		sum[blk[i]] += a[i];
		if(i > 1 && blk[i] != blk[i - 1]) L[blk[i]] = i, R[blk[i - 1]] = i - 1; // 只有在断点处更新，注意最开始的区间要特判
	}
	L[blk[1]] = 1, R[blk[n]] = n; // 最开始的区间特判，数目不够sz就改最后区间的右端点编号
	
	int q; cin >> q;
	while(q--)
	{
		ll op, l, r; cin >> op >> l >> r;
		if(op == 1)
		{
			ll x; cin >> x;
			Add(l, r, x);
		}
		else cout << query(l, r) << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 10
// 1 6 1 7 6 10 8 2 7 4 
// 5
// 2 8 10
// 2 3 3
// 2 1 8
// 2 5 7
// 2 3 3

// 13
// 1
// 41
// 24
// 1