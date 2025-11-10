// 要求每个点距离其为9的点的数量，一种朴素的思路就是对每个点跑dfs，求距离为9的点的数量，但是这样显然会超时。
// 实际上，有许多信息是可以复用的。比如对一棵以1为根的树，其中某一个节点的距离其为9的点肯定要从它的子树，以及
// 它的根节点路径去找，只要计算两类节点数目求和即可得到答案。

// Problem: 小红的⑨
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/121300/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define eb emplace_back

const int N = 2e5 + 7, K = 10;

// down[u][d] ：以u为根的子树中，与u距离恰好为 d的节点数量（d范围 0~9）。
// up[u][d］ ：不在u的子树中，与u距离恰好为 d的节点数量（d范围 1~9，因为距离 0 的节点只有u自身，且属于子树内）。
int up[N][K], down[N][K];
vector<int> g[N];

// 常规自底向上dfs，求子树到根距离
void dfs1(int x, int pre)
{
	down[x][0] = 1;
	for(auto& y : g[x])
	{
		if(y == pre) continue;
		dfs1(y, x);
		for(int i = 1; i <= 9; i++) down[x][i] += down[y][i - 1];
	}
}

// 换根的关键，自顶向下dfs
// 换根体现在 dfs2 中通过父节点的完整信息（子树 + 非子树）推导子节点的非子树信息，模拟根从父节点转移到子节点的过程。
void dfs2(int x, int pre)
{
    // 自顶向下，肯定是用父节点更新子节点，于是用x更新y
    // 并将dfs调用放在最后，确保父节点更新完了才轮到子节点更新
	for(auto& y : g[x])
	{
		if(y == pre) continue;
		for(int i = 1; i <= 9; i++)
		{
            // 这里的down[x][i-1]包括了自己子树的信息，所以后面要消去影响
			up[y][i] = up[x][i - 1] + down[x][i - 1];
			if(i >= 2) up[y][i] -= down[y][i - 2];
		}
		dfs2(y, x);
	}
}

void solve()
{
	int n; cin >> n;
	for(int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].eb(v), g[v].eb(u);
	}
	
	dfs1(1, 0);
	dfs2(1, 0);
	
	for(int i = 1; i <= n; i++) cout << up[i][9] + down[i][9] << ' ';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 10
// 1 2
// 2 3
// 3 4
// 4 5
// 5 6
// 6 7
// 7 8
// 8 9
// 9 10

// 1 0 0 0 0 0 0 0 0 1