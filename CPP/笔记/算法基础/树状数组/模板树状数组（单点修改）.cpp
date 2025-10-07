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
using ll = long long;

const int N = 2e5 + 9;
int n, q;
ll a[N], t[N];//a�������룬ͬʱ�����޸ġ�t��ʾһ�γ���Ϊlowbit����ĺ͡�

int lowbit(int x) { return x & -x; }//lowbit����ȡ�ó��ȣ���������Ǹ��ݶ��������ģ��������Ե� 

void update(int k, ll x)//���ڸ���t����,��k��ʼ��ֱ��nΪֹȫ��t�������x
{
	for (int i = k; i <= n; i += lowbit(i)) t[i] += x;//ע�����������ͨ����lowbit�� 
}

ll getsum(ll x)//��������ǰ׺��
{
	ll res = 0;				//ע����������õ���-lowbit�� 
	for (int i = x; i > 0; i -= lowbit(i)) res += t[i];//ͨ��-lowbitʵ�����
	return res;
}

void solve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) update(i, a[i]);

	while (q--)
	{
		int op; cin >> op;
		if (op == 1)
		{
			ll k, v; cin >> k >> v;
			update(k, v);
		}
		else
		{
			ll l, r; cin >> l >> r;
			cout << getsum(r) - getsum(l - 1) << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//5 4
//1 2 3 4 5
//1 1 1
//2 1 2
//1 4 2
//2 3 4
//
//4
//9
