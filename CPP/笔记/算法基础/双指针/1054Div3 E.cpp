// Problem: CF 2149 E
// Contest: Codeforces - Codeforces Round 1054 (Div. 3)
// URL: https://codeforces.com/contest/2149/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 7;

int a[N], n;

ll f(int k, int len)
{
    if (k < 0 || len < 0) return 0;

    ll res = 0;
    int cnt = 0;
    map<int, int> mp; // 当有大量同样的值时，unordered_map效率低下
    for (int i = 1, j = 1; j <= n; j++)
    {
        if (!mp[a[j]]++) cnt++;
        while (cnt > k) if (mp[a[i++]]-- == 1) cnt--; //对不同数数量的限制
        res += min(j - i + 1, len); //对长度的限制
    }

    return res;
}

void solve()
{
    int k, l, r;
    cin >> n >> k >> l >> r;
    for (int i = 1; i <= n; i++) cin >> a[i];

    cout << f(k, r) - f(k, l - 1) - f(k - 1, r) + f(k - 1, l - 1) << '\n'; // 容斥原理
    // f(x, y)表示不同数的数量<=x，长度<=y的子数组数量
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int _; cin >> _;
    while (_--) solve();

    return 0;
}

// 5
// 1 1 1 1
// 5
// 5 2 2 3
// 1 2 1 3 2
// 6 3 1 6
// 1 2 3 1 2 3
// 4 1 1 2
// 7 7 7 7
// 7 3 2 4
// 1 2 1 2 3 2 1

// 1
// 5
// 10
// 7
// 5