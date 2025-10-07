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

// 快速幂取模函数：计算 (a^b) % c 的结果
ll qmi(ll a, ll b, ll c)
{
    a %= c;     // 开头先取一次模
    ll res = 1; // 初始化结果为1
    while (b) // 当指数b不为0时继续循环
    {
        if (b & 1) // 检查b是否为奇数（最低位是否为1）
            res = res * a % c; // 如果是奇数，则将当前的a乘到结果中，并对c取模

		//注意！！！：不能改为*=，否则优先级会有问题 

        a = a * a % c; // 将a平方并对c取模，准备下一轮迭代
        b >>= 1; // b右移一位（相当于b除以2），减少指数
    }

    return res; // 返回最终的结果
}

void solve()
{
    ll a, b, c; cin >> a >> b >> c;

    cout << qmi(a, b, c) << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

//2
//3 4 100
//5 2 20
//
//81
//5
