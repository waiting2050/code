#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;
ll a[N], pre[N], suf[N];

ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}

void solve()
{	//有多组测试样例，记得初始化 
	memset(pre, 0, sizeof(pre));
	memset(suf, 0, sizeof(suf));
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	//运用前缀的性质去预处理 
	for(int i = 1; i <= n; i++) pre[i] = gcd(pre[i - 1], a[i]);
	for(int i = n; i >= 1; i--) suf[i] = gcd(suf[i + 1], a[i]);
	
	ll ans = pre[n];//有可能不用修改 
	for(int i = 1; i <= n; i++) ans = max(ans, gcd(pre[i - 1], suf[i + 1]));
	
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}

// 4
// 3
// 61 40 2 
// 7
// 92 68 20 54 14 33 82 
// 3
// 39 88 18 
// 2
// 57 75 

// 2
// 2
// 3
// 75
