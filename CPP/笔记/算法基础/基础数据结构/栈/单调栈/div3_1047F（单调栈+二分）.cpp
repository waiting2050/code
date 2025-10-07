// Problem: CF 2137 F
// Contest: Codeforces - Codeforces Round 1047 (Div. 3)
// URL: https://codeforces.com/contest/2137/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//这道题得分成三种情况考虑。1.a[i]==b[i]，此时将其赋值给z[i]，z[i]一定能对答案产生贡献。
//2.a[i]>b[i],位置i之前必须得有j,使a[j]>a[i]才能满足前缀最大相同。3. a[i]<b[i]，位置i之前必须得有j,使a[j]>b[i]才能满足前缀最大相同 
//最后计算答案时，可以用贡献法。需要一个能快速求某区间第一个比某个数值大的数据结构，这里可以用st表，线段树，树状数组等，本题做法选择了单调栈+二分 
//因为要同时大于a[i],b[i]，首先单调栈可以保证大于a[i]成立，再加上具有单调性可以使用二分可以快速处理b[i] 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 7;

int a[N], b[N], stk[N];

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n + 1; i++) stk[i] = 0;
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	ll ans = 0;
	int top = 0;
	for(int i = 1; i <= n; i++)
	{
		while(top && a[stk[top]] < a[i]) top--;
		
		if(a[i] == b[i]) ans += i * (n - i + 1ll);
		else
		{
			int mx = max(a[i], b[i]); //其实比a[i]小的已经pop了，可以省略a[i] 
			
			int l = 0, r = top + 1;
			while(l + 1 ^ r)
			{
				int mid = (l + r) >> 1;
				if(a[stk[mid]] >= mx) l = mid;
				else r = mid;
			}
			
			ans += stk[l] * (n - i + 1ll); //如果没有符合条件的l会是0，stk[0]=0 
		}
		
		stk[++top] = i;
	}
	
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

// 6
// 3
// 5 3 1
// 4 2 1
// 5
// 1 2 3 4 5
// 1 2 3 4 5
// 6
// 7 1 12 10 5 8
// 9 2 4 3 6 5
// 1
// 1
// 2
// 6
// 5 1 2 6 3 4
// 3 1 6 5 2 4
// 2
// 2 2
// 1 1
// 
// 5
// 35
// 26
// 0
// 24
// 1
