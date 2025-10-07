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

//单调栈主要用于解决与下一个更大元素或下一个更小元素相关的问题。

const int N = 2e5 + 9;
ll a[N], l[N];//a存放输入的元素，l存放结果

void solve()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	stack<ll> stk;//存放比较过程中的中间value

	for (int i = 1; i <= n; i++)
	{
		while (stk.size() && stk.top() >= a[i]) stk.pop();//当栈不为空且栈顶元素大于等于a[i]，弹出

		if (stk.empty()) l[i] = -1;//如果为空，说明左边没有比a[i]更小的了，让l[i]=-1
		else l[i] = stk.top();//否则，取第一个比a[i]小的

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
