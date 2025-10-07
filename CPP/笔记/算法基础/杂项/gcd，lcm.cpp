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

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }//lcm*gcd就等于a*b，某些情况会用上 

void solve()
{
    ll a, b; cin >> a >> b;

    cout << gcd(a, b) << ' ' << lcm(a, b) << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

//输入测试组数
//接下来每一行两个数，分别是a， b 
//3
//6 9
//12 3
//5 7
//
//3 18
//3 12
//1 35
