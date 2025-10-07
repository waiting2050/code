// Problem: CF 2124 C
// Contest: Codeforces - EPIC Institute of Technology Round Summer 2025 (Codeforces Round 1036, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/2124/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

//首先ai|ai+1，但是加入了x以后，这种性质被破坏了，产生了三种可能 1.bi=ai,bi+1=ai+1或bi=ai*x,bi+1=ai*x，此时
//bi|bi+1一定是成立的 2.bi=ai+1,bi+1=ai+1*x，bi|bi+1依然成立 3.bi=ai*x,bi+1=ai+1，此时无法整除了，
//但是有x=bi/gcd(bi,bi+1)。第1,2种情况不影响x，只用考虑第3种情况就好，x应该为所有可能的xi的lcm

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 6e5 + 7;

ll b[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    ll ans = 1;
    for (int i = 1; i < n; i++)
    {
        int t = b[i] / (__gcd(b[i], b[i + 1]));
        ans = lcm(ans, t);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int _;
    cin >> _;
    while (_--)
        solve();

    return 0;
}

// 4
// 2
// 2 4
// 3
// 1 1000000000 500000000
// 4
// 4 8 4 8
// 7
// 42 42 14 84 28 73080 255780
//
// 343
// 2
// 4
// 6