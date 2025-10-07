// Problem: С��������
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/105623/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

ll dp[N], a[N];//ǰn������ɵ�����

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	memset(dp, 0, sizeof(ll) * (n + 1));
	
	for(int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] + a[i];//ѡ��ǰ�� 
		if(i >= 2) dp[i] = max(dp[i], dp[i - 2]);//��ȥ��ǰ����ǰһ���� 
		if(i >= 3) dp[i] = max(dp[i], dp[i - 3]);//��ȥ��ǰ����ǰ������ 
	}
	
	cout << dp[n] << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}

//2
//12
//1 3 -2 -1 -4 -1 -2 5 -4 15 -10 9
//5
//1 2 3 4 5
//
//20
//15
