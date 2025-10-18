// Problem: CF 2162 G
// Contest: Codeforces - Codeforces Round 1059 (Div. 3)
// URL: https://codeforces.com/contest/2162/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 根据样例
// n=2: -1      
// n=3: 1-3-2           sum=9
// n=4: 1-3 1-2 1-4      sum=9
// n=4: 1-2-4 2-3       sum=16（自己举例）
// 随n增大，完全平方和sum也应该增大，假设选取sum=n^2(随便选一个)，就要想办法维护增量为(n+1)^2-n^2=2*n+1
// 由n=4,可以看作1-2-3 2-n，要构造2*n+1，可以拆成n+(n+1)  ps：n即4，为了方便观察，将n-1，n-2...用数字代换
// 那么将n从2连到3，则+n成立；再将新增的n+1连到1上面，就可以得到n=5
// 由上面的构造：
// n=5: 5-1-2-3-4       sum=25
// 可以将n=5看作n-1-2-3-(n-1)，同理，将n连到2上面构造+n，再将n+1连到1上，构造+n+1
// 同理可以得到n=6,n=7...

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
	int n; cin >> n;
	
	if(n == 2) cout << -1 << '\n';
	else if(n == 3) cout << "1 3\n2 3\n";
	else if(n == 4) cout << "1 2\n3 1\n4 1\n";
	else
	{
		cout << "1 2\n2 3\n3 4\n";
		cout << 1 << ' ' << n << '\n';
		for(int i = 5; i < n; i++) cout << 2 << ' ' << i << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 3
// 2
// 3
// 4
// 
// -1
// 1 3
// 2 3
// 1 2
// 3 1
// 4 1