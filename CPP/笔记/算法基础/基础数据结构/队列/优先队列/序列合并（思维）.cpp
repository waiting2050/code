#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;

struct P
{
	ll v;//a[x]+b[y]，即序列合并的值 
	int x, y;//分别记录a，b的下标 
	
	bool operator < (const P& p) const
	{
		return v > p.v;//按照值升序排列 
	}
};
priority_queue<P> pq;
int a[N], b[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++) pq.push({b[1] + a[i], i, 1});
	
	for(int i = 1; i <= n; i++)
	{
		ll v = pq.top().v;
		int x = pq.top().x, y = pq.top().y; pq.pop();
		cout << v << ' ';
		if(y + 1 <= n) pq.push({a[x] + b[y + 1], x, y + 1});//每次输出完最小值后，继续往下探索
		//例如，a[2]+b[1]是当前最小值，因为b[1]+a[1,n]已经加入队列，那么接下来a[2]+b[2]可能是最小的 
	}
	
	return 0;
}

//3
//2 6 6
//1 4 8
//
//3 6 7
