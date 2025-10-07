#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;
ll a[N], dp[N], dq[N];
int hh = 1, tt = 0;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++)
	{
		//��ͷ�Ϸ��� 
		while(tt >= hh && dq[hh] < i - k) hh++;//��һ��ĵ���ջ��ͬ��������ѶԶ�ͷ�Ͷ�β���жϲ𿪣����������ݵĴ�������м� 
		//��Ϊһ�����Ŀ��ġ�dp�������ȸ��ģ��������dp�Ǵ����Ժ�õ��� 
		
		dp[i] = dp[dq[hh]] + a[i];
		
		//��β������ 
		while(tt >= hh && dp[i] >= dp[dq[tt]]) tt--;
		
		dq[++tt] = i;
	}
	
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans += dp[i];
	cout << ans;
	
	return 0;
}

// 5 3
// 1 2 3 4 5
// 
// 35
