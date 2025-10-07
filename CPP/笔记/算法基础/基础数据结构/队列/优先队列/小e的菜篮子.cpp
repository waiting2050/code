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

////��С��������
//struct cmp
//{
//	bool operator ()(const ll& u, const ll& v)const
//	{
//		return u > v;//С���ѣ�top����С
//	}
//};//�ٰ�priority_queue<ll>��Ϊpriority_queue<ll, vector<ll>, cmp>����

void solve()
{
	int q; cin >> q;
	priority_queue<ll> pq;//Ĭ���Ǵ���ѣ�Ҳ����������top
	ll sum = 0;				//��С����һ��priority_queue<ll, vector<ll>, greater<ll>>��ΪС����

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
