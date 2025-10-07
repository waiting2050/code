// Problem: 
//     P1464 Function
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1464
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 27;
ll rem[N][N][N];

ll w(ll a, ll b, ll c)
{
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	else if(a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	else if(rem[a][b][c]) return rem[a][b][c];
	else if(a < b && b < c) return rem[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return rem[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1); 
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	ll a, b, c;
	while(cin >> a >> b >> c && !(a == -1 && b == -1 && c == -1))
		cout << "w(" << a << ", " << b << ", " << c << ") " << "= " << w(a, b, c) <<'\n';
	
	return 0;
}

