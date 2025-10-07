#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;

ll a[N], b[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	ll n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	sort(a + 1, a + 1 + n);//基于贪心很容易想到 
	
	ll ans = 0;
	for(ll i = 1; i <= n; i++)//此时a，b都是固定了的，但是b是无序的，所以对a二分。从前找b里面小于a的元素，相当于从后找a里面大于b的元素 
		ans += n - (upper_bound(a + i, a + 1 + n, b[i]) - a) + 1;//注意这里是从a+i开始不是从a+1开始 
	
	cout << ans;
	
	return 0;
}

//5
//3 1 4 1 5
//2 7 1 8 3
//
//7
