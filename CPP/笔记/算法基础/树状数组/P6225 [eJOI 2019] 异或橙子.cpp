// Problem: Luogu P6225
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6225
// Memory Limit: 62 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// a₂ ⊕ a₃ ⊕ a₄ ⊕ (a₂ ⊕ a₃) ⊕ (a₃ ⊕ a₄) ⊕ (a₂ ⊕ a₃ ⊕ a₄)
// 化简一下得到: a₂ ⊕ a₄
// 显然，根据按位异或的性质，区间内的 a 的出现次数将决定是否产生贡献，也就是 l, r 的奇偶性，或者说是区间长度的奇偶性。
// • 当 l, r 奇偶性不同，也就是区间长度 r − l + 1 为偶数，所有 a 的出现次数都是偶数次，没有产生贡献，答案为 0。
// • 当 l, r 奇偶性相同，也就是区间长度 r − l + 1 为奇数，所有下标与 l 奇偶性相同的数产生了贡献。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 7;

int t[2][N], a[N], n;

int lowbit(int x) {return x & -x;}

void update(int (&tr)[], int k, int x) {for(int i = k; i <= n; i += lowbit(i)) tr[i] ^= x;}

int query(int (&tr)[], int k)
{
	int res = 0;
	for(int i = k; i; i -= lowbit(i)) res ^= tr[i];
	
	return res;
}

void solve()
{
	int q; cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) update(t[i & 1], i, a[i]);
	
	while(q--)
	{
		int op, l, r; cin >> op >> l >> r;
		if(op == 1)
		{
			int k = l & 1;
			update(t[k], l, a[l] ^ r); //这里的修改始终是针对a数组，因为a数组存的是真实信息，而t数组是修饰后的
			a[l] = r;                  // a[l]^(a[l]^r)=r
		}
		else
		{
			if((l + r) & 1) cout << 0 << '\n';
			else cout << (query(t[l & 1], r) ^ query(t[l & 1], l - 1)) << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 3 3
// 1 2 3
// 2 1 3
// 1 1 3
// 2 1 3
// 
// 2
// 0
// 
// 
// 5 6
// 1 2 3 4 5
// 2 1 3
// 1 1 3
// 2 1 5
// 2 4 4
// 1 1 1
// 2 4 4
// 
// 2
// 5
// 4
// 4