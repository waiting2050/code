// Problem: AT ABC425 F
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Autumn (AtCoder Beginner Contest 425)《独特视角编程大赛 2025 年秋季（AtCoder 初级赛 425）》
// URL: https://atcoder.jp/contests/abc425/tasks/abc425_f
// Memory Limit: 1024 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 逆向思考，插入n位的方案数即删除n位的方案数

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 25, P = 998244353;

ll dp[1 << 25]; //1表示该位字符未被删除

void solve()
{
	int n; cin >> n;
	string s; cin >> s;
	
    // 假设n为3，那么sta就是7，即111,。事实上(1<<k)-1一定是全1
	int sta = 1 << n;
	dp[sta - 1] = 1;
	
	for(int i = sta - 1; i >= 0; i--) //找每一种字符串长度的可能，倒序确保正确更新
	{
		char pre = '?'; //防止多次删除，比如aab，删除第一个或第二个a得到的都是ab，实际方案数是加1而非加2
		for(int j = 0; j < n; j++) //寻找删除每一位字符的可能
		{
			if(((i >> j) & 1) && pre ^ s[j]) //这一位上面要有字符同时不能与上一位重复
			{
				int ni = i ^ (1 << j); //由if里的条件可知，此时i和(1<<j)一定都是1
				dp[ni] = (dp[ni] + dp[i]) % P;
				pre = s[j];
			}
		}
	}
	
	cout << dp[0]; //删光的方案数
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 3
// aab
// 
// 3
// 
// 
// 7
// atcoder
// 
// 5040
// 
// 
// 22
// atcoderbeginnercontest
// 
// 115732070