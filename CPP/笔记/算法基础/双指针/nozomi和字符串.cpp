// Problem: nozomi和字符串
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/118654/F
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 7;

int pre[N];

void solve()
{
	int n, k; cin >> n >> k;
	string s; cin >> s;
	s = "?" + s;
	
    int c0 = 0, c1 = 0, ans = 0;
	for(int i = 1, l = 1; i <= n; i++)
    {
        s[i] == '0' ? c0++ : c1++;
        while(c0 > k && c1 > k) s[l++] == '0' ? c0-- : c1--;
        ans = max(ans, i - l + 1);
    }
    cout << ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 5 1
// 10101

// 3