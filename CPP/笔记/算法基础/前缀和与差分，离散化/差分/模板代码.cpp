#include <iostream>
using namespace std;
using  ll = long long;

const int N = 1e5 + 10;
ll a[N], prefix[N], diff[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, p, q; cin >> n >> p >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) diff[i] = a[i] - a[i - 1];

	while (p--)
	{
		ll l, r, x; cin >> l >> r >> x;

		diff[l] += x; diff[r + 1] -= x;
	}

	for (int i = 1; i <= n; i++) a[i] = a[i - 1] + diff[i];
	for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + a[i];

	while (q--)
	{
		int l, r; cin >> l >> r;
		cout << prefix[r] - prefix[l - 1] << '\n';
	}

	return 0;
}
