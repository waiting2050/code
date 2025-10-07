#include <iostream>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll a[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (q--)
    {
        ll x; cin >> x;

        int l = 0, r = n;//l一定要从0开始 
        while (l + 1 != r)
        {
            int mid = (l + r) >> 1;

            if (x > a[mid]) l = mid;
            else r = mid;
        }

        if (a[r] == x) cout << r << ' ';
        else cout << -1 << ' ';
    }

    return 0;
}
