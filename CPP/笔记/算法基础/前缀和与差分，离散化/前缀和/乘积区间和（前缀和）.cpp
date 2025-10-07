#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 7;
const int mod = 1e9 + 7;
ll a[N], b[N], c[N], pa[N], pb[N], pc[N];

ll mo(ll x) {return x > 0 ? x % mod : (x % mod + mod) % mod;}//注意这里如果x是负数的情况 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++) pb[i] = mo(pb[i - 1] + b[i]);
	for(int i = 1; i <= n; i++) pa[i] = mo(pa[i - 1] + a[i]);
	for(int i = 1; i <= n; i++) c[i] = mo(a[i] * pb[i - 1]);
	for(int i = 1; i <= n; i++) pc[i] = mo(pc[i - 1] + c[i]);
	
	while(q--)
	{
		int l, r; cin >> l >> r;
		cout << mo(mo(pb[r] * mo(pa[r] - pa[l - 1])) - pc[r] + pc[l - 1]) << '\n';
	}
	
	return 0;
}

// 5 3
// 1 2 3 4 5
// -1 2 8 1 -6
// 1 3
// 2 4
// 2 5
// 
// 53
// 53
// 999999976
