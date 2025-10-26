// Problem: 小苯的区间选数2.0
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/119895/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 本题显而易见是贪心，对每个区间，按照左端点升序排序，然后让id为最大的mex备选，从0开始，然后看id被哪些区间包含
// 在这些区间里，优先选择更短的，也就是右端点更靠左的，如果有：id++，删除当前区间。如果没有，说明当前id就是最大mex了
// 赛时发现了这个贪心的性质，但是太久没用优先队列，不知道怎么动态的维护这个特定左端点下区间最短，特此记录（用set会自动去重）

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back
#define fi first
#define se second

const int N = 2e5 + 7;

pair<int, int> a[N];

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + 1 + n);
	
	int id = 0, i = 1;
	priority_queue<int, vector<int>, greater<int>> pq;
	while(1)
	{
		while(i <= n && a[i].fi <= id)
		{
			pq.push(a[i].se);
			i++;
		}
		
		while(pq.size() && pq.top() < id) pq.pop();

		if(pq.empty()) break;
		pq.pop();
		id++;
		if(id > n) break;
	}
	
	cout << id << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 2
// 5
// 0 2
// 0 1
// 3 3
// 3 4
// 2 5
// 3
// 1 1
// 2 2
// 3 3

// 5
// 0