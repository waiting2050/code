#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int pre[N], sz[N], d[N];

int find(int x) {return pre[x] == x ? x : find(pre[x]);}

int mo(int x) {return (x % 2 + 2) % 2;}

//获取某一点到根节点的距离 
int getd(int x)
{
	int res = 0;
	while(pre[x] != x)
	{
		res += d[x];
		x = pre[x];
	}
	
	return res;
}

void merge(int x, int y)
{
	int fx = find(x), fy = find(y);
	if(fx == fy) return;
	
	if(sz[fx] > sz[fy]) swap(fx, fy);
	//1=getd(x)+d[fx]-getd(y)，getd为点到根的距离，d[fx]为合并以后根fx到根fy的距离 
	pre[fx] = fy, sz[fy] += sz[fx], d[fx] = mo(1 + getd(y) - getd(x)); 
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++) pre[i] = i, sz[i] = 1;
	
	while(q--)
	{
		int op, x, y; cin >> op >> x >> y;
		if(op == 1) merge(x, y);
		else
		{
			int fx = find(x), fy = find(y);
			if(fx != fy) cout << "Unknown\n"; //不是同一个根节点 
			else
			{
				if(mo(getd(x) - getd(y)) == 1) cout << "NO\n"; //两点取模距离为1，是敌人 
				else cout << "YES\n"; //取模距离为0，是朋友 
			}
		}
	}
	
	return 0;
}

//5 4
//1 1 2
//2 1 2
//1 2 3
//2 1 3
//
//NO
//YES
