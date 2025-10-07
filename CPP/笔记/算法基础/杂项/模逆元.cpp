#include <iostream>
#include <cstdio>
#include <string>
#include <climits>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <random>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;

ll p = 998244353;

// 快速幂取模函数：计算 (a^b) % c 的结果
ll qmi(ll a, ll b)
{
    a %= p;     // 开头先取一次模
    ll res = 1; // 初始化结果为1
    while (b) // 当指数b不为0时继续循环
    {
        if (b & 1) // 检查b是否为奇数（最低位是否为1）
            res = res * a % p; // 如果是奇数，则将当前的a乘到结果中，并对c取模

        a = a * a % p; // 将a平方并对c取模，准备下一轮迭代
        b >>= 1; // b右移一位（相当于b除以2），减少指数
    }

    return res; // 返回最终的结果
}

// 计算x的模逆元，即求解 x * inv(x) ≡ 1 (mod p)，利用费马小定理，inv(x) = x^(p-2) mod p
ll inv(ll x) { return qmi(x, p - 2); }

ll f(ll a, ll b, ll c, ll x)
{
    return (a * x % p + b)%p * inv(c * x % p) % p;
}

void solve()
{
    ll a, b, c, q; cin >> a >> b >> c >> q;
    while (q--)
    {
        ll x; cin >> x;
        cout << f(a, b, c, x) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

//1
//7 1 17 3
//19
//25
//1
//
//6181080
//664713299
//528482305
