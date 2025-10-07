#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

struct Node
{
	int val, son[2];
}t[N << 5];

struct P
{
	int id, t, x, k;
	
	bool operator<(const P& p) const
	{
		return t < p.t;
	}
};
vector<P> v;
int a[N], ans[N], idx;

void insert(int x)
{
	int o = 0;
	t[o].val++;//根节点计数+1 
	for(int i = 30; i >= 0; i--)
	{
		int y = x >> i & 1;
		int& u = t[o].son[y];//别忘记引用 
		
		if(!u) u = ++idx;//不存在就动态开点 
		o = u;//更新当前节点 
		t[o].val++;//更新当前节点计数 
	}
}

int query(int x, int k)
{
	int o = 0, res = 0;
	for(int i = 30; i >= 0; i--)
	{
		int y = x >> i & 1;
		int u = t[o].son[y], v = t[o].son[!y];//异或以后，u是小点，v是大点 
		
		if(u && k <= t[u].val) o = u;//如果确定在左边 
		else
		{
			o = v;
			k -= u ? t[u].val : 0;//因为0作为根节点，若直接减去根节点权值显然是错误的 
			res |= 1 << i;//不同数异或结果为1 
		} 
	}
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	//先对t元素进行升序排序，因为每次询问[1,t]之间的元素，如果t是混乱的那么就需要不断对01trie进行插入和删除 
	for(int i = 1; i <= q; i++)
	{
		int t, x, k; cin >> t >> x >> k;
		v.push_back({i, t, x, k});
	}
	sort(v.begin(), v.end());
	
	int now = 0;
	for(auto&[id, t, x, k] : v)
	{
		while(now < t) insert(a[++now]);
		ans[id] = query(x, k);//等会按照询问顺序输出 
	}
	
	for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
	
	return 0;
}

//5 3
//1 5 3 4 3
//3 100 2
//5 20 4
//1 30 1
//
//101
//23
//31
