#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;

int a[N], maxq[N], minq[N];

//思路：先随便找一个区间，计算极差，再扩大这个区间（将区间往右延伸），会发现极差只会更大或不变，不会更小。
//于是得出结论，如果区间不合法，则其超区间也不合法，所以考虑用双指针来构造区间。
//先将左右端点放在开头（下标为1处），不断延伸右端点并且统计合法区间数量，直到不合法时，移动左端点。
//这个时候区间最值是动态变化的，考虑用单调队列来维护区间最值。 
 

void solve()
{
	int n, m; cin >>n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	ll ans = 0;
	int l = 1, mihh = 1, mitt = 0, mxhh = 1, mxtt = 0;
	for(int r = 1; r <= n; r++)//l,r是双指针部分 
	{
		while(mihh <= mitt && a[r] <= a[minq[mitt]]) mitt--;//队尾合法性 
		minq[++mitt] =r;
		
		while(mxhh <= mxtt && a[r] >= a[maxq[mxtt]]) mxtt--;
		maxq[++mxtt] = r;
		
		while(mihh <= mitt && mxhh <= mxtt && a[maxq[mxhh]] - a[minq[mihh]] > m)
		{
			l++;
			
			while(mihh <= mitt && minq[mihh] < l) mihh++;//队头合法性 
			while(mxhh <= mxtt && maxq[mxhh] < l) mxhh++;
		}
		
		ans += r - l + 1;
	}
	
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}

//2
//5 2
//1 3 2 5 9
//6 3
//1 1 4 5 1 4
//
//8
//11
