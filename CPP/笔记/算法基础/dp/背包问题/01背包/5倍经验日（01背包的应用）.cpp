// Problem: Luogu P1802
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1802
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7;

int dp[N], t[N], l[N], w[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, x; cin >> n >> x;
	for(int i = 1; i <= n; i++) cin >> l[i] >> w[i] >> t[i];
	
	for(int i = 1; i <= n; i++)
	{
		//����ͨ��01�����������������������ѡ�Ļ���ֵҲ��Ϊ0������Ҫ��취������С��ֵ 
		for(int j = x; j >= t[i]; j--)//�����������㹻ʱ���������ѡҲҪ����l[i] 
			dp[j] = max(dp[j] + l[i], dp[j - t[i]] + w[i]);
		for(int j = t[i] - 1; j >= 0; j--)//����������㣬ҲҪ����ÿ���п��ܵ���ͼ�ֵ 
			dp[j] += l[i];
	}
	
	cout << dp[x] * 5ll;//��ֹ�������ݷ�Χ 
	
	return 0;
}

//6 8
//21 52 1
//21 70 5
//21 48 2
//14 38 3
//14 36 1
//14 36 2
//
//1060
