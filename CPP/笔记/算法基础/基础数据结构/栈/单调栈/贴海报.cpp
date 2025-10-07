#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5;
int a[N], stk[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	
	int d; 
	for(int i = 1; i <= n; i++) cin >> d >> a[i];
	
	int top = 0, ans = 0;
	for(int i = 1; i <= n; i++)
	{
		//维护一个严格单调递增的栈 
		while(top && a[stk[top]] > a[i]) top--;
		
		//从循环出来以后，a[stk[top]]肯定<或=a[i]，如果等于，那么前面的一栋楼被覆盖了，这个状态可以转移给他
		//如果小于，那么就没有状态转移，必须得新开一张海报
		//本质就是找该元素左边离他最近小于等于它的元素
		if(a[stk[top]] ^  a[i]) ans++;
		
		stk[++top] = i;
	}
	
	cout << ans;
	
	return 0;
}

//5
//1 2
//1 3
//2 2
//2 5
//1 4
//
//4
