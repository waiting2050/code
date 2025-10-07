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
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
int a[N], mx[N], mi[N];

void solve()
{
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	multiset<int> st;//st�������
	
	for (int i = 1; i <= n; i++)
	{
		st.insert(a[i]);
		if (i >= k) mi[i] = *st.begin(), mx[i] = *st.rbegin(), st.erase(st.find(a[i - k + 1]));//�������������һ�����ڣ���¼�����Сֵ������������������ߵ�Ԫ��
	}

	for (int i = k; i <= n; i++) cout << mx[i] << " \n"[i == n];//i!=n,����ո�i==n�������
	for (int i = k; i <= n; i++) cout << mi[i] << " \n"[i == n];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//8 3
//0 3 1 0 - 5 2 1 8
//
//3 3 1 2 2 8
//0 0 - 5 - 5 - 5 1
