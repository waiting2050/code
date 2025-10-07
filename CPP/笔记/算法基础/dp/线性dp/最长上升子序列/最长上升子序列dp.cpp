#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ai:= �����еĵ� i �������±�� 1 ��ʼ��
// dp(i):= �� ai Ϊ��β�������е���󳤶� 
// ��������Ҫ���������ϸ񵥵���������ô��� j<i �� aj<ai����һ��Ԫ�� ai �Ϳ��Խӵ� aj �ĺ��棬��ô dp(i)=dp(j)+1.
// Ϊ����������������Ǳ��� [1,i)��ȡ���ֵ���ɡ�
const int N = 1e3 + 7;
ll a[N], dp[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++)
	{
		//ע��j��0��ʼ����Ϊj=0ʱ������dp=max(dp,dp+1),�Ὣdp[1]��ֵΪ1
		for(int j = 0; j < i; j++)
			if(a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1ll);
	}
			
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	
	cout << ans;
  	
  	return 0;
}

// 6
// 1 5 3 4 7 6
// 
// 4
