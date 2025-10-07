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
using ll = long long;//��ÿ�������ұ߱���С�����������൱����ÿ������߱����������
//Ϊʲô�ǵ�����߱�����ģ���Ϊǰ׺��ֻ�ܴ��������� 

const ll N = 2e5 + 9;
ll a[N], t[N];//t����״�ļ�������
vector<ll> X;

ll lowbit(ll x) { return x & -x; }

//ֻҪ���޸ľ�Ҫupdate
void update(ll k, ll x)//��k����Ϊ�±꣬xΪֵ
{
	for (int i = k; i <= X.size(); i += lowbit(i)) t[i] += x;//ע������iҪ<=X.size(),��Ϊ�Ƕ���ɢ���Ժ����������޸�
}

ll bs(ll x)//��ɢ�����Ҷ�Ӧ�±�
{
	return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;//��״�����±��1��ʼ������Ҫ��+1
}

ll getsum(ll k)
{
	ll res = 0;
	for (int i = k; i > 0; i -= lowbit(i)) res += t[i];
	return res;
}

void solve()
{
	ll n; cin >> n;//��Ϊt�Ǽ������飬ai������1e9������ɢ���Ļ�Ҫ�úܴ�ļ������顣
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		X.push_back(a[i]);
	}

	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());

	ll ans = 0;
	for (int i = 1; i <= n; i++)//�ؼ��Ĳ��裺һ��ʼt�����ǿյģ���ÿһ��ѭ������ �������ֵ�����-С�ڵ��ڵ�ǰ�±��ӦԪ�ص��������� ���õ����ڸ�Ԫ�ص���������
	{																										//��ΪgetsumҪ����һ���±꣬���Դ��±��ȥ
		ans += getsum(X.size()) - getsum(bs(a[i]));
		update(bs(a[i]), 1);//�ڲ�ѯ���Ժ󣬽��и��¡�Ҳ����˵����һ�β�ѯ��t�ǿյģ��ڶ�����һ�����֣��Դ����ơ�
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
