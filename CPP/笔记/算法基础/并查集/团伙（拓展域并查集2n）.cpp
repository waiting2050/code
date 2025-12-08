#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7;
int pre[N << 1];

int find(int x)
{
	return pre[x] = (pre[x] == x ? x : find(pre[x]));
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n << 1; i++) pre[i] = i;
	
	while(m--)
	{
		char op; cin >> op;
		int p, q; cin >> p >> q;
		
		// 1.我们必须让1---n为根，否则在循环中会因为n+1--2n为根而丢失情况。！！所以只能pre[find(p+n)]=find(q),不能pre[find(p)]=find(q+n) 
		// 2.如果两个人是盆友，我们不需要使他们的反面相连, 2是3的敌人，4是5的敌人，3与4是盆友，但我们不能说2与5是盆友
		//所以不能写pre[find(p+n)]=pre[find(q+n)] 
		if(op == 'E') 
		{
			pre[find(p + n)] = find(q);
			pre[find(q + n)] = find(p);
		}
		else pre[find(p)] = find(q);
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(pre[i] == i) cnt++;
		
	cout << cnt;
	
	return 0;
}

// 6
// 4
// E 1 4
// F 3 5
// F 4 6
// E 1 2
// 
// 3
