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
int a[N];//a����վ��

void solve(void)
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];

	stack<int> stk;//stack�ǳ�վ
	int pos = 1;//pos��a������±�

	for (int i = 1; i <= n; i++)//i��Ϊ��վ��Ҫ�ı�ţ�������i=1,˵�����Ϊ1�ĳ���Ҫ��վ��
	{
		while (pos <= n && (stk.empty() || stk.top() != i)) stk.push(a[pos++]);//����վ�ڻ��г������ҳ�վͷ������Ҫ�ı��ʱ���ѳ�������վ	
																				//�����ջ��Ϊ�գ�top���������empty��������empty����Ӱ����
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
