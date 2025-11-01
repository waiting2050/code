// 开根对所有区间都是单独修改，但是有一个优化，考虑到数据范围是1~1e9，只要开根5次就一定为1，所以保险起见，
// 只要一个区间被开根修改了6次及以上就不用再修改，因为再怎么开根所有元素都是1。
// 将区间和储存在sum里，询问单位区间时直接使用

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 1e5 + 7;

ll a[N], L[N], R[N], blk[N], sum[N], tag[N];

void Sqrt(int l, int r)
{
	for(int i = l; i <= r; i++)
	{
		sum[blk[i]] -= a[i];
		a[i] = sqrt(a[i]);
		sum[blk[i]] += a[i];
	}
}

void update(int l, int r)
{
	if(blk[l] == blk[r]) return Sqrt(l, r);
	
	Sqrt(l, R[blk[l]]);
	for(int i = blk[l] + 1; i < blk[r]; i++)
	{
		if(tag[i] >= 6) continue;
		tag[i]++;
		Sqrt(L[i], R[i]);
	}
	Sqrt(L[blk[r]], r);
}

ll query(int l, int r)
{
	ll res = 0;
	if(blk[l] == blk[r])
	{
		for(int i = l; i <= r; i++) res += a[i];
		return res;
	}
	
	for(int i = l; i <= R[blk[l]]; i++) res += a[i];
	for(int i = blk[l] + 1; i < blk[r]; i++) res += sum[i];
	for(int i = L[blk[r]]; i <= r; i++) res += a[i];
	
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
		sum[blk[i]] += a[i];
		if(i > 1 && blk[i - 1] != blk[i]) L[blk[i]] = i, R[blk[i - 1]] = i - 1;
	}
	L[blk[1]] = 1, R[blk[n]] = n;
	
	int q; cin >> q;
	while(q--)
	{
		int op, l, r; cin >> op >> l >> r;
		if(op == 1)	update(l, r);
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
// 1 7 3 10 1 4 4 3 10 4 
// 5
// 2 1 1
// 2 5 9
// 2 5 10
// 2 2 2
// 1 6 8

// 1
// 22
// 26
// 7