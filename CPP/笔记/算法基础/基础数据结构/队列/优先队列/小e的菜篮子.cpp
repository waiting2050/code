#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <random>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;

////改小方法二：
//struct cmp
//{
//	bool operator ()(const ll& u, const ll& v)const
//	{
//		return u > v;//小根堆，top是最小
//	}
//};//再把priority_queue<ll>改为priority_queue<ll, vector<ll>, cmp>即可

void solve()
{
	int q; cin >> q;
	priority_queue<ll> pq;//默认是大根堆，也就是最大的在top
	ll sum = 0;				//改小方法一：priority_queue<ll, vector<ll>, greater<ll>>改为小根堆

	while (q--)
	{
		int op; cin >> op;

		if (op == 1)
		{
			ll x; cin >> x;
			pq.push(x);
			sum += x;
		}
		else if (!pq.empty())
		{
			sum -= pq.top();
			pq.pop();
		}
	}

	cout << sum;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
