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

//����ջ��Ҫ���ڽ������һ������Ԫ�ػ���һ����СԪ����ص����⡣

const int N = 2e5 + 9;
ll a[N], l[N];//a��������Ԫ�أ�l��Ž��

void solve()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	stack<ll> stk;//��űȽϹ����е��м�value

	for (int i = 1; i <= n; i++)
	{
		while (stk.size() && stk.top() >= a[i]) stk.pop();//��ջ��Ϊ����ջ��Ԫ�ش��ڵ���a[i]������

		if (stk.empty()) l[i] = -1;//���Ϊ�գ�˵�����û�б�a[i]��С���ˣ���l[i]=-1
		else l[i] = stk.top();//����ȡ��һ����a[i]С��

		stk.push(a[i]);
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
