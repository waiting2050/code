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
#include <cmath>
using namespace std;
using ll = long long;

const int N = 5e3 + 10, M = 5e5 + 9;
int a[N];
bool dp[M];

void solve(void)
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	dp[0] = 1;//һ�����ֶ���ѡҲ��һ����� 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 5e5; j >= a[i]; j--)//Ҫ�Ӻ���ǰ��������Ȼ���ܻ��ظ����� 
		{
			dp[j] |= dp[j - a[i]];//j-a[i]�õ��±�Ϊj��Ԫ��a[i]��λ����ǰ��Ԫ����1��0 
		}//�����1����ô��˵����������ɼ���a[i]�Ժ�õ������� �� 
	}
	ll cnt = 0;
	for (int i = 0; i <= 5e5; i++) cnt += dp[i];

	cout << cnt;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
