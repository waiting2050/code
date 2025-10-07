#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int a[N], pre[N], sz[N]; //����ʽ�ϲ����˸�sz���� 

int find(int x) {return pre[x] == x ? x : find(pre[x]);} //����ʽ�ϲ���Ҫ�������ṹ�����Բ���·��ѹ�� 

void merge(int x, int y)
{
	int fx = find(x), fy = find(y);
	if(fx == fy) return;
	
	// x->y
	if(sz[fx] > sz[fy]) swap(fx, fy); //����ʽ�ϲ��Ĳ�֮ͬ�� 
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
	for(int i = 1; i <= n; i++) if(find(i) == i) ans = max(ans, a[i]);//ע����һ�в��ܸ������һ�𣬷�����ܻ��¼û���������ֵΪans 
	
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
