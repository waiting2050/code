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
ll a[N], l[N], stk[N], top;//stk�д�ŵ����±�

void solve()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++)
	{
		while (top && a[stk[top]] >= a[i]) top--;//top--�൱�ڵ���stk.topԪ�� 

		if (top)l[i] = a[stk[top]];
		else l[i] = -1;

		stk[++top] = i;//�ǵ�Ҫ��++top,��Ϊstk[top]��λ���Ѿ�����a[stk[top]]<a[i]���±� 
	}

	for (int i = 1; i <= n; i++) cout << l[i] << ' ';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//5
//7 8 5 6 7
//
//-1 7 -1 5 6
