// Problem: 无穷无尽的小数
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/123788/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 设x=0.s1s2s3...sl...，那么10^l*x=s1s2s3...sl.s1s2s3...sl...，用10^l*x-x=s1s2s3...sl，这个就是循环节
// 即循环节=s1s2s3...sl/(10^l-1)，也就是说循环节的分母是等位数的9，分子就是循环节本身。那么a，b可以先把长度变一致，
// 再相减就是循环节，如果a<b，要借位->把a-b的结果加上分母。
// 用lcm将a,b长度变一致，然后相减就是循环节。然后再判断是否需要借位

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}

int lcm(int a, int b) {return a / gcd(a, b) * b;}

string sub(string a, string b)
{
	string res;
	
	int br = 0;
	for(int i = a.size() - 1; i >= 0; i--)
	{
		int da = a[i] - '0';
		int db = b[i] - '0';
		int dif = da - db - br;

		if(dif < 0) br = 1, dif += 10;
		else br = 0;
		
		res += to_string(dif);
	}
	
	reverse(res.begin(), res.end());
	return res;
}

void solve()
{
	int n, m; cin >> n >> m;
	string ka, kb; cin >> ka >> kb;
	
	int len = lcm(n, m);
	string a, b;
	for(int i = 1; i <= len / n; i++) a += ka;
	for(int i = 1; i <= len / m; i++) b += kb;
	
	string ans;
	if(a >= b) ans = sub(a, b);
	else
	{
		ans = sub(b, a);
		
		string aux;
		for(int i = 1; i <= len; i++) aux += "9";
		ans = sub(aux, ans);
	}
	
	cout << ans.size() << '\n';
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 1 1
// 2
// 3

// 1
// 8