#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 1e6 + 7, B = 131; //B是进制 

string s;
ull b[N], h[N]; //b是简化pow函数的数组，h是字符串的前缀数组
//eg：ABA-A00=BA 

ull getHash(int l, int r) {return h[r] - h[l - 1] * b[r - l + 1];}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n >> s;
	s = "?" + s;
	
	int q; cin >> q;
	
	b[0] = 1; //这个容易漏 
	for(int i = 1; i <= n; i++)
	{
		b[i] = b[i - 1] * B;
		h[i] = h[i - 1] * B + s[i] - 'a' + 1;
	}
	
	while(q--)
	{
		int l, r, x, y; cin >> l >> r >> x >> y;
		cout << (getHash(l, r) == getHash(x, y) ? "YES" : "NO") << '\n';
	}
	
	return 0;
}

//6
//abcabc
//3
//1 4 2 4
//1 3 4 6
//2 3 5 6
//
//NO
//YES
//YES
