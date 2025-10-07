#include <iostream>
#include <cstdio>
#include <string>
#include <climits>
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
using ll = long long;//找每个数字右边比它小的数量，就相当于找每个数左边比他大的数量
//为什么非得找左边比它大的：因为前缀和只能从左往右找 

const ll N = 2e5 + 9;
ll a[N], t[N];//t是树状的计数数组
vector<ll> X;

ll lowbit(ll x) { return x & -x; }

//只要有修改就要update
void update(ll k, ll x)//将k设置为下标，x为值
{
	for (int i = k; i <= X.size(); i += lowbit(i)) t[i] += x;//注意这里i要<=X.size(),因为是对离散化以后的数组进行修改
}

ll bs(ll x)//离散化后找对应下标
{
	return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;//树状数组下标从1开始，所以要加+1
}

ll getsum(ll k)
{
	ll res = 0;
	for (int i = k; i > 0; i -= lowbit(i)) res += t[i];
	return res;
}

void solve()
{
	ll n; cin >> n;//因为t是计数数组，ai数量级1e9，不离散化的话要用很大的计数数组。
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		X.push_back(a[i]);
	}

	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());

	ll ans = 0;
	for (int i = 1; i <= n; i++)//关键的步骤：一开始t数组是空的，在每一个循环里用 所有数字的数量-小于等于当前下标对应元素的数字数量 ，得到大于该元素的数字数量
	{																										//因为getsum要的是一个下标，所以传下标进去
		ans += getsum(X.size()) - getsum(bs(a[i]));
		update(bs(a[i]), 1);//在查询完以后，进行更新。也就是说，第一次查询，t是空的，第二次有一个数字，以此类推。
	}

	cout << ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//5
//2 3 1 1 6
//
//4
