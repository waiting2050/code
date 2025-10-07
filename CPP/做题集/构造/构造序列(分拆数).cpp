// Problem: 构造序列
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/117762/E
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// k部分拆数
// 将 n 分成恰有 k 个部分的分拆，称为 k部分拆数，记作 p(n,k)。
// p(n,k) =p(n-1,k-1)+p(n-k,k)

// 互异分拆数
// 互异分拆数：pdn。自然数n的各部分互不相同的分拆方法数。
// pd(n,k) =pd(n - k,k- 1) + pd(n- k,k)

#include <bits/stdc++.h>
    using namespace std;
using ll = long long;
using ull = unsigned long long;

const int P = 1e9 + 7;

ll qmi(ll a, ll b)
{
    a %= P;
    ll res = 1;
    while (b)
    {
        if (b & 1)  res = res * a % P;
        
        a = a * a % P;
        b >>= 1;
    }

    return res;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll mx = (ll)(sqrt(8 * n + 1) - 1) >> 1;
    vector dp(n + 7, vector<ll>(mx + 7)); //dp[i][j]表示将i拆成j个相异的数的方案数

    dp[0][0] = 1;
    for (ll i = 1; i <= n; i++)
        for (int j = 1; j <= min(mx, i); j++)
            dp[i][j] = (dp[i - j][j] + dp[i - j][j - 1]) % P; //分成两种情况，1.没有1，对j个数都减1，还是选j个数
                                            //2.有1，还是对j个数减1，然后选择之前为1现在为0的这个数，接下来要选j-1个数

    ll ans = 0;
    for (int i = 1; i <= mx; i++)
        ans = (ans + m * qmi(m - 1, i - 1) % P * dp[n][i] % P) % P;

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int _ = 1;
    while (_--)
        solve();

    return 0;
}

// 10 114514
//
// 870525937
//
//
// 3 2
//
// 4