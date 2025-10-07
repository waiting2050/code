#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;
int pre[N], c[N];
vector<int> v;//v存储每个连通块大小，比如有3座城市，那么大小就为3 

void init(int n)
{
	for(int i = 1; i <= n; i++)
		pre[i] = i;
}

int find(int x) {return pre[x] = (pre[x] == x ? x : find(pre[x]));}

void merge(int u, int v) {pre[find(u)] = find(v);}

//核心函数
//将所有连通块分为两类：1.只有一座城市 2.不少于两座城市
//思路：总共可延伸道路-二类城市间的道路数 >= 一类城市所需道路数 
bool check(int k)
{
	ll cnt1 = 0, temp = 0;//cnt1存储第一类，temp记录城市总数（也就是总共可以延伸多少条道路） 
	for(auto& y : v)
	{
		if(y == 1) cnt1++;
		else temp += min(y, k);//城市总数=（连通块所包含的城市数，二分枚举出的可延伸数）取小 
	}
	
	ll sum = temp - 2 * (v.size() - 1 - cnt1);//v.size-1：比如说有三个连通块，那么一共需要2条道路来连接 
	return sum >= cnt1;						  //为什么*2？因为a和b间修了一条路=a修了一条+b修了一条（总共可延伸道路本身就重复计算了） 
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	init(n);
	
	for(int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		merge(u, v);
	}
	
	for(int i = 1; i <= n; i++)	c[find(i)]++;
	for(int i = 1; i <= n; i++)
		if(find(i) == i) v.push_back(c[i]);	
	
	ll l = -1, r = 1e9;
	while(l + 1 != r)
	{
		ll mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	
	cout << (check(r) ? r : -1);//注意<<的优先级比?:高，所以要用括号 
	
	return 0;
}

//4 2
//1 2
//3 4
//
//1
