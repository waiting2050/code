#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 130;
ll a[N][N], prefix[N][N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];

	ll mx = 0;
	for(int x1 = 1; x1 <= n;x1++)
		for(int y1 = 1 ;y1 <= n; y1++)
			for(int x2 = x1; x2 <= n; x2++)
				for (int y2 = y1; y2 <= n; y2++)
				{
					mx = max(mx, prefix[x2][y2] + prefix[x1 - 1][y1 - 1] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1]);
				}

	cout << mx;

	return 0;
}
