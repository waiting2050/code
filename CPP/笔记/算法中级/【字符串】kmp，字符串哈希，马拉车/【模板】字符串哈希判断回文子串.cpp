#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 1e6 + 7, B = 131;

string s;
ull b[N], h[N], hr[N]; //多了个后缀哈希hr[] 

ull getHash(int l, int r) {return h[r] - h[l - 1] * b[r - l + 1];}

ull getHashRev(int l, int r) {return hr[l] - hr[r + 1] * b[r - l + 1];} //求后缀哈希，注意hr里下标变了，但是b里下表没变 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n >> s;
	s = "?" + s;
	
	b[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		b[i] = b[i - 1] * B;
		h[i] = h[i - 1] * B + s[i] - 'a' + 1;
	}
	for(int i = n; i >= 1; i--) hr[i] = hr[i + 1] * B + s[i] - 'a' + 1;
	
	int q; cin >> q;
	while(q--)
	{
		int l, r; cin >> l >> r;
		cout << (getHash(l, r) == getHashRev(l, r) ? "YES\n" : "NO\n");
	}
	
	return 0;
}

//6
//ababab
//3
//1 3
//2 4
//1 4
//
//YES
//YES
//NO
