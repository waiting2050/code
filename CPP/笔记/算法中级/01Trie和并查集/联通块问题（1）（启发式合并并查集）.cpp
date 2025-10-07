#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int a[N], pre[N], sz[N]; //启发式合并多了个sz数组 

int find(int x) {return pre[x] == x ? x : find(pre[x]);} //启发式合并需要保留树结构，所以不能路径压缩 

void merge(int x, int y)
{
	int fx = find(x), fy = find(y);
	if(fx == fy) return;
	
	// x->y
	if(sz[fx] > sz[fy]) swap(fx, fy); //启发式合并的不同之处 
	pre[fx] = fy;
	sz[fy] += sz[fx];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) pre[i] = i, sz[i] = 1;
	
	int m; cin >> m;
	while(m--)
	{
		int u, v; cin >> u >> v;
		merge(u, v);
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) if(find(i) != i) a[find(i)] ^= a[i];
	for(int i = 1; i <= n; i++) if(find(i) == i) ans = max(ans, a[i]);//注意这一行不能跟上面放一起，否则可能会记录没处理完的数值为ans 
	
	cout << ans;
	
	return 0;
}

// 3
// 1 2 3
// 3
// 1 2
// 2 3
// 1 3
// 
// 0
// 
// 
// 3
// 2 2 3
// 1
// 1 2
// 
// 3
