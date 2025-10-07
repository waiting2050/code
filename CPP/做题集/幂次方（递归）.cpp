// Problem: 
//     P1010 [NOIP 1998 普及组] 幂次方
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1010
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void div(int n)
{
	for(int i = 15; i >= 0; i--)
	{
		if(pow(2, i) <= n)
		{
			if(i == 0) cout << "2(0)";
			else if(i == 1) cout << "2";
			else
			{
				cout << "2(";
				div(i);
				cout << ')';
			}
			
			n -= pow(2, i);
			if(n ^ 0) cout << '+';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	div(n);
	
	return 0;
}

