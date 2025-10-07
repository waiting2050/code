#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 507;

int pre[N * (N + 1)];
struct P
{
	int u, v, w;
	
	bool operator < (const P& p) const
	{
		return w < p.w;
	}
};
vector<P> r;

int find(int x) {return pre[x] = (pre[x] == x ? x : find(pre[x]));}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int a, b; cin >> a >> b;
	
	for(int i = 0; i <= b; i++) pre[i] = i;
	
	//设置一个序号为零的节点（精髓所在），此点直接连接的节点即为通过花费a元直接购买的物品。
	for(int i = 1; i <= b; i++) r.push_back({0, i, a});
	
	for(int i = 1; i <= b; i++)
	{
		for(int j = 1; j <= b; j++)
		{
			int w; cin >> w;
			if(w) r.push_back({i, j, w});
		}
	}

	sort(r.begin(), r.end());

	ll ans = 0;
	for(auto& y : r)
	{
		if(find(y.u) == find(y.v)) continue;
		ans += y.w;
		pre[find(y.u)] = find(y.v);
	}
	
	cout << ans;
	
	return 0;
}

//1 1
//0
//
//1
//
//
//3 3
//0 2 4
//2 0 2
//4 2 0
//
//7
