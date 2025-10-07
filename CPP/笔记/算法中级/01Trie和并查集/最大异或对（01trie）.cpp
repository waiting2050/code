#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int a[N], idx;
struct Node
{
	int val, son[2];
}t[N * 32];//a[i]最大到1e9,比2^30略小，所以开到2^31次方足够了 

void insert(int x)
{
	int o = 0;//0就是最上面的根节点，所以每次从0开始 
	for(int i = 30; i >= 0; i--)
	{
		int y = x >> i & 1;//y是0或1 
		int& u = t[o].son[y];//判断当前节点所指向的下一个为y的点是否存在 
		
		if(!u) u = ++idx;//若不存在则动态开点，若存在则不管 
		o = u;//更新当前节点的编号 
	}
}

int getmax(int x)
{
	int o = 0, res = 0;
	for(int i = 30; i >= 0; i--)
	{
		int y = x >> i & 1;
		int u = t[o].son[y], v = t[o].son[!y];
		if(v)
		{
			o = v;
			res |= 1 << i;
		}
		else o = u;
	}
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	insert(a[1]);//题目要求两个数异或的结果，先放进去一个 
	
	int ans = 0;
	for(int i = 2; i <= n; i++) 
	{
		ans = max(ans, getmax(a[i]));
		insert(a[i]);
	}
	
	cout << ans << '\n';
	
	return 0;
}

// 5
// 1 3 2 4 5
// 
// 7
