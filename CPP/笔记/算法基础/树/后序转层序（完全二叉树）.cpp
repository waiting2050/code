#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 30 + 7;

int t[N], a[N], idx, n;

// 如果是前序，就把t[o]=a[++idx]放在两个buildtree前
void buildtree(int o)
{
	if(o > n) return;
	
	buildtree(o << 1);
	buildtree(o << 1 | 1);
	
	t[o] = a[++idx];
}

void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	buildtree(1);
	
	for(int i = 1; i <= n; i++)
	{
		cout << t[i];
		if(i ^ n) cout << ' ';
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 8
// 91 71 2 34 10 15 55 18

// 18 34 55 71 2 10 15 91