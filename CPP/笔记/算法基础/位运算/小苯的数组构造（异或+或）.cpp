// Problem: 小苯的数组构造
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/105623/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//只用考虑四种情况，x和y分别是：[0,0],[0,1],[1,0],[1,1]
void solve()
{
	int n, x, y; cin >> n >> x >> y;
	vector<int> ans(n + 1);
	
	if((x & y) != y)//y一定是x的子集，相当于特判某一位x=0，y=1的情况
	{
		cout << "NO\n";
		return;
	}
	
	int skip = 1;//标记跳过的数字，范围[1,n]。因为要确保ans里存的都是正数，所以贪心，能放1尽量放1，没被skip标记的可以放0 
	for(int i = 31; i >= 0; i--)
	{
		int a = (x >> i & 1), b = (y >> i & 1);//这里一定要&，不然取出来的不是一位数 
		if(!a) continue;//上面判断过了[0,1]，这里判断的是[0,0]，都为0没必要再操作 
		
		bool flag = (a ^ b) ^ (n & 1);//flag==1相当于特判[1,0]且n为偶数，或者[1,1]且n为奇数的情况，此时每一位都置1就行 
		if(flag)
		{
			for(int j = 1; j <= n; j++)
				ans[j] |= 1 << i;
		}
		else//否则在特定位数放0，其余置1 
		{
			for(int j = 1; j <= n; j++)
			{
				if(j == skip) continue;
				ans[j] |= 1 << i;
			}
			skip++;
		}
	}
	
	int cmp1 = 0, cmp2 = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!ans[i])//判断条件3 
		{
			cout << "NO\n";
			return;
		}
		
		cmp1 |= ans[i];
		cmp2 ^= ans[i];
	}
	
	if(cmp1 != x || cmp2 != y) cout << "NO\n";//是否符合条件1，2 
	else
	{
		cout << "YES\n";
		for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}

//2
//2 3 1
//3 2 3
//
//YES
//2 3
//NO
