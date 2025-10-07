#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v;

void solve()
{
    ll n; cin >> n;

    for (ll i = 2; i <= n / i; i++)
    {
        if (n % i) continue;

        v.push_back(i);
        while (n % i == 0) n /= i;
    }
    if (n > 1) v.push_back(n);

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
