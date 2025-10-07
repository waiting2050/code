#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 7;

int pre[N], sz[N], top;
pair<int, int> stk[N]; //用一个栈存储merge的信息，方便之后撤销 

int find(int x) {return pre[x] == x ? x : find(pre[x]);}

void merge(int x, int y)
{
	int fx = find(x), fy = find(y);
	if(fx == fy) return;
	
	if(sz[fx] > sz[fy]) swap(fx, fy);
	stk[++top] = {fx, fy}; //入栈 
	pre[fx] = fy;
	sz[fy] += sz[fx];
}

void undo()
{
	if(!top) return; //如果栈为空 
	
	//撤销之前merge做的修改 
	auto[x, y] = stk[top--];
	pre[x] = x;
	sz[y] -= sz[x];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++) pre[i] = i, sz[i] = 1;
	
	while(q--)
	{
		int op; cin >> op;
		if(op == 2) undo();
		else
		{
			int x, y; cin >> x >> y;
			if(op == 1) merge(x, y);
			else
			{
				if(find(x) == find(y)) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
	
	return 0;
}

// 4 5
// 1 1 2
// 1 1 3
// 3 2 3
// 2
// 3 2 3
// 
// YES
// NO
