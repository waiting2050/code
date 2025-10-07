// Problem: Luogu P12000
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P12000
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 7;

struct P
{
	ll hl, summ;//汇率，总钱数
} dq[N];
ll a[N], n;//汇率 
ll b[N];//收入 

//check思路：显而易见需要贪心，在汇率高的位置尽可能兑换，除非完成不了要求不得不在没那么好的位置兑换。如果从左往右枚举很难想出最优策略，
//那不如从右往左枚举，对于第i个位置所需要x个游戏币，那就往左找出汇率最高点然后兑换（尽量少兑换一点，因为之后可能有更高的汇率），同时注意
//汇率的更新是在线的（每遍历一个右端点就要更新一次）。那么单调队列就符合这个要求，并且注意在那一天身上的钱够不够兑换，不够的话要找汇率的次高点。 

bool check(ll mid)
{
	int hh = 1, tt = 0;
	ll sum = 0, supg = 0, usem = 0;//当前的总钱数，剩余的游戏币数，已经用了多少钱
	for(int i = 1; i <= n; i++)//相当于枚举右端点，找在其之前所有的最佳的可供兑换的情况 
	{
		sum += b[i];
		
		//队头的合法性由summ维护，因为没有明确的区间，只有当钱不得不用在那一天完的时候才将其弹出 
		//队列的区间是从右端点往左的所有数，当左端点不合法（没钱换游戏币）时弹出 
		while(tt >= hh && a[i] >= dq[tt].hl) tt--;//队尾的合法性
		dq[++tt] = (P){a[i], sum};
		
		if(supg < mid) 
		{
			//用单调队列在线维护汇率最大值，当所有能在汇率最高点兑换的钱用完之后才考虑在次高点兑换
			//因为不确定之后会不会有更高的汇率，所以每次尽量少兑换 
			while(tt >= hh && supg < mid)//当队列非空且游戏币不足mid个（因为有可能要多次兑换） 
			{
				ll supm = dq[hh].summ - usem;//最多能在hh处使用的钱
				ll needg = mid - supg;//需要的游戏币数
				ll needm = min(supm, ((needg + dq[hh].hl - 1 )/ dq[hh].hl));//需要的钱数（小技巧：+dq[hh].hl-1相当于ceil，加上分母-1） 
				
				usem += needm;
				supg += needm * dq[hh].hl;
				if(!(supm - needm)) hh++;
			}
			if(supg < mid) return false;//如果队列空了（换无可换）且不满足mid的要求时返回非 
		}
		supg -= mid;
	}
	
	return true;
}

void solve()
{
	cin >> n;
	
	ll mx = 0, lim = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]);
	for(int i = 1; i <= n; i++) cin >> b[i], lim += b[i] * mx;
	
	ll l = 0, r = lim / n + 1;//注意这里需要用ll，否则会爆int 
	while(l + 1 != r)
	{
		ll mid = (l + r) >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	
	cout << l << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}

// 3
// 5
// 1 2 3 4 5
// 5 4 3 2 1
// 5
// 1 1 1 1 1
// 2 3 4 5 6
// 9
// 9 9 8 2 4 4 3 5 3
// 10 10 10 10 10 10 10 10 10
// 
// 5
// 2
// 55
