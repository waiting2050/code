// Problem: Luogu P12143
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P12143
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string a; cin >> a;
	a = " " + a;
	int n = a.size() - 1;
	
	int brk = 0;
	ll ans = 1;//长度为1的第一个子串特判 
	for(int l = 1, r = 1; r <= n; r++)//枚举每一个右端点 
	{
		//if(r == 1) continue;//特判 
		if(a[r - 1] != a[r] && a[r - 1] + 1 != a[r]) brk++;//判断断点 
		while(brk > 1)//一旦断点过多，就要把左区间右移，想办法得到最靠右的合法左区间 
		{
			l++;
			if(a[l] != a[l - 1] && a[l] - 1 != a[l - 1]) brk--;
		}
		
		ans += r - l + 1;//本质相当于统计合法左端点个数，每个合法左端点都可以与当前右端点构成一个有效子串。（包括以自己为左右端点的区间） 
	}
	
	cout << ans;
	
	return 0;
}

//12258
//
//12
//
//
//97856
//
//13
