#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;
ll a[N];

bool check(ll mid, int n, int k)
{
	ll sum = 0;
	for(int i = 1; i <= n; i++)
		sum += min(mid, a[i]);
		
	return sum >= k * mid;
//	这个的充分性如何理解：
//	假设n=5,k=3,mid=2,从五堆糖果里每次从三堆糖果里拿一个，拿两次，
//	假设三堆糖果数为0，那么即使剩下的两堆数量很多也无法成立，但是
//	此时 min(mid, a[i]),导致 sum=2*mid不符合k(k=3)*mid ，所以check
//	函数的充分性是成立的 
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	ll l = 0, r = 2e14 + 7;
	while(l + 1 ^ r)
	{
		ll mid = (l + r) >> 1;
		if(check(mid, n, k)) l = mid;
		else r = mid;
	}
	
	cout << l << '\n';
	
	return 0;
}

// 5 3
// 2 8 2 3 9
// 
// 7
