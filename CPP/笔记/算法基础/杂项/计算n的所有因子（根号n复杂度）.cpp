#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v;

void solve()
{
    ll n; cin >> n;

    for (ll i = 1; i <= n / i; i++)
    {
        if (n % i) continue;

        v.push_back(i);
        if (i != n / i) v.push_back(n / i);//比如16，防止4被放入两次 
    }

    sort(v.begin(), v.end());

    for (auto& ele : v) cout << ele << ' ';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1; 
    while (t--) solve();

    return 0;
}
