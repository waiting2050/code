#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

//考虑用二分去求最长的长度，但是直接二分会不符合单调性。比如长为5的字符串，比他短一点的是3，而不是4。
//所以这道题的二分要分奇偶，此时单调性是成立的 

const int N = 1e6 + 7, B = 131;

int n;
string s;
ull h[N], hr[N], b[N];

ull getHash(int l, int r)
{
	return h[r] - h[l - 1] * b[r - l + 1];
}

ull getHashRev(int l, int r)
{
	return hr[l] - hr[r + 1] * b[r - l + 1];
}

bool check(int x)
{
	for(int i = 1; i + x - 1 <= n; i++)
	{
		int j = i + x - 1;
		if(getHash(i, j) == getHashRev(i, j)) return true;
	}
	
	return false;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> s;
	s = "?" + s;
	
	b[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		b[i] = b[i - 1] * B;
		h[i] = h[i - 1] * B + s[i] - 'a' + 1;
	}
	for(int i = n; i >= 1; i--) hr[i] = hr[i + 1] * B + s[i] - 'a' + 1;

	int l = 0, r = n + 1, ans = 1;
	while(l + 1 != r)
	{
		int mid = (l + r) >> 1;
		if(check(mid * 2 - 1)) l = mid;
		else r = mid;
	}
	ans = max(ans, 2 * l - 1);

	l = 0, r = n + 1;
	while(l + 1 != r)
	{
		int mid = (l + r) >> 1;
		if(check(mid << 1)) l = mid;
		else r = mid;
	}
	ans = max(ans, l << 1);
	
	cout << ans;
	
	return 0;
}

//6
//ababab
//
//5
