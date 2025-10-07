#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <random>
#include <stack>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int a[N];//a是入站口

void solve(void)
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];

	stack<int> stk;//stack是车站
	int pos = 1;//pos是a数组的下标

	for (int i = 1; i <= n; i++)//i即为出站口要的编号，（比如i=1,说明编号为1的车需要出站）
	{
		while (pos <= n && (stk.empty() || stk.top() != i)) stk.push(a[pos++]);//当入站口还有车，并且车站头不是我要的编号时，把车开进车站	
																				//（如果栈顶为空，top会错误，所以empty），加上empty不会影响结果
		if (stk.top() == i)stk.pop();
		else
		{
			cout << "No";
			return;
		}
	}

	cout << "Yes";
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
