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

const int N = 3e5 + 9;//һ�β���+����ѯ����ൽ3e5
vector<ll> X;//������ɢ������ת���±ꡣ
ll a[N];//�������к������

struct Q//add����ӵĲ�����que����ѯ�ʵĲ���
{
	ll a, b;
}add[N], que[N];

int bs(ll x)//�ؼ�����������ɢ�ĵ���±�תΪ�����������±�
{
	return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
}

void solve()
{
	ll n, q; cin >> n >> q;

	//X�Ƕ�aת�����м�����������a������ܳ��ֵĵ㶼Ҫ�ȴ�X��һ��
	for (int i = 1; i <= n; i++)
	{
		ll x, w; cin >> x >> w;
		X.push_back(x);
		add[i] = { x, w };
	}
	//add��queҪ��ת���Ժ������a������д��������ȼ�¼����
	for (int i = 1; i <= q; i++)
	{
		ll l, r; cin >> l >> r;
		X.push_back(l), X.push_back(r);
		que[i] = { l, r };
	}

	//X����ȥ��
	sort(X.begin(), X.end());//��Ϊa�����±��С��������XҲҪ����
	X.erase(unique(X.begin(), X.end()), X.end());//��Ϊ���е���Ψһ�ģ�һ������Բ�����Σ���ֻ�ܴ���һ��

	for (int i = 1; i <= n; i++)//��ת�����a������мӷ�����
	{
		int idx = bs(add[i].a);
		a[idx] += add[i].b;
	}
	for (int i = 1; i <= X.size(); i++) a[i] += a[i - 1];//��ǰ׺�ͣ�ע��������X.size() 

	for (int i = 1; i <= q; i++)//��ת�����a�������ѯ��
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
