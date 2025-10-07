#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <random>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;

const int N = 3e5 + 9;//一次操作+两次询问最多到3e5
vector<ll> X;//用于离散化处理，转化下标。
ll a[N];//重新排列后的数组

struct Q//add负责加的操作，que负责询问的操作
{
	ll a, b;
}add[N], que[N];

int bs(ll x)//关键函数，将零散的点的下标转为连续的数组下标
{
	return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
}

void solve()
{
	ll n, q; cin >> n >> q;

	//X是对a转化的中间量，所有在a数组可能出现的点都要先从X走一遍
	for (int i = 1; i <= n; i++)
	{
		ll x, w; cin >> x >> w;
		X.push_back(x);
		add[i] = { x, w };
	}
	//add和que要在转化以后才能在a数组进行处理，所以先记录下来
	for (int i = 1; i <= q; i++)
	{
		ll l, r; cin >> l >> r;
		X.push_back(l), X.push_back(r);
		que[i] = { l, r };
	}

	//X排序并去重
	sort(X.begin(), X.end());//因为a数组下标从小到大，所以X也要升序
	X.erase(unique(X.begin(), X.end()), X.end());//因为所有点是唯一的，一个点可以操作多次，但只能存在一个

	for (int i = 1; i <= n; i++)//对转化后的a数组进行加法操作
	{
		int idx = bs(add[i].a);
		a[idx] += add[i].b;
	}
	for (int i = 1; i <= X.size(); i++) a[i] += a[i - 1];//求前缀和，注意这里是X.size() 

	for (int i = 1; i <= q; i++)//对转化后的a数组进行询问
	{
		ll l = bs(que[i].a);
		ll r = bs(que[i].b);
		cout << a[r] - a[l - 1] << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//4 2
//0 2
//3 3
//1 5
//0 1
//0 1
//1 3
//
//8
//8
