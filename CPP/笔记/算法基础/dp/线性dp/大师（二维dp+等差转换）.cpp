// Problem: Luogu P4933
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4933
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7, P = 998244353, V = 2e4 + 7;

ll dp[N][V * 2], a[N];//dp[i][j]��iΪ��β����Ϊj�ķ�����

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	ll ans = 0;
	for(int i = 1; i <= n; i++)//ö����ÿ������β 
	{
		for(int j = i - 1; j >= 1; j--)//ö��i��ǰ��ÿ������˳��ö�ٹ��� 
		{
			int diff = a[i] - a[j] + 1;//���㹫�� 
			dp[i][diff] = (dp[i][diff] + dp[j][diff] + 1) % P;//dp[j][diff]�ķ�����+ֻ��������j,i�ķ���
			ans = (ans + dp[j][diff] + 1) % P;//ͬ�ϣ�ע������Ҫ����dp[j][diff]������dp[i][diff]��������ظ����� 
		}
		//ps:���һ����ǰ�������ַ�������ô�����������������ַ������棨������ͬ�����ټ����²�����ǰһ������������ķ��� 
	}
	
	cout << (ans + n) % P;//��Ҫ����ֻ��һ�����ķ����� 
	
	return 0;
}

// 8
// 13 14 6 20 27 34 34 41
// 
// 50
