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
ll a[N], td[N], tid[N];//td[]��tid���ǲ�֣�������������״�ģ����������Ĳ�������ڷ���ʱ������

int lowbit(int x) { return x & -x; }//lowbit��ȡ��һ�����ȣ���Ȼ�����±��������ģ����������±�ĸ�������lowbitΪ��λ���ġ�

void update(int k, ll x)//������״����
{
	for (int i = k; i <= n; i += lowbit(i)) td[i] += x, tid[i] += k * x;//k���±�
}//Ϊʲô��k*x����i*x,��Ϊ������Ҫ����k��ʼ��n�����鶼����k*x���޸ģ�ÿ���޸���һ���ġ�
//����Ϊ��״�Ĳ���������а�����ϵ�ģ����Զ��ӽڵ��޸����Ժ�ҲҪ�Ը��ڵ��޸ġ���

ll getsum(ll x)//������Ĳ�ѯ
{
	ll res = 0;
	for (int i = x; i > 0; i -= lowbit(i)) res += (x + 1) * td[i] - tid[i];//���ݹ�ʽ�õ���
	return res;
}

void solve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) update(i, a[i]), update(i+1, -a[i]);//�Բ������td, tid�ĸ��£���ֵ�������һ����

	while (q--)
	{
		int op; cin >> op;
		if (op == 1)
		{
			ll l, r, v; cin >> l >> r >> v;
			update(l, v), update(r + 1, -v);
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
//1 1 3 1
//2 1 2
//1 4 5 2
//2 3 4
//
//5
//10
