// Problem: Luogu P1140
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1140
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100 + 7;

int d[6][6] =
{
	{0,  0,  0,  0,  0,  0},
	{0,  5, -1, -2, -1, -3},
	{0, -1,  5, -3, -2, -4},
	{0, -2, -3,  5, -2, -2},
	{0, -1, -2, -2,  5, -1},
	{0, -3, -4, -2, -1,  0}
};
unordered_map<char, int> mp;
int a[N], b[N], dp[N][N];//a��ǰi�������b��ǰj�������������ƶ�

//ÿһλ�޷����������1.�ǿնԷǿգ�2.�ǿնԿգ�3.�նԷǿա�4.�նԿգ������ڣ� 
//�κ�һλ������п��ܺͿռ�����ϣ����ǲ��ù��ĵ��ײ�����ٿռ����ֻ��Ҫʹÿһλ������ж�Ӧ�Ϳ��� 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
	mp['A'] = 1, mp['C'] = 2, mp['G'] = 3, mp['T'] = 4;
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		char ch; cin >> ch;
		a[i] = mp[ch];
	}
	
	int m; cin >> m;
	for(int i = 1; i <= m; i++)
	{
		char ch; cin >> ch;
		b[i] = mp[ch];
	}
	
	//��״̬ת�Ʒ����Ƶã���i-1/j-1/[i-1,j-1]�������Ե�֪���ʼ��dp[0][0]��dp[i][0]��dp[0][i]�� 
	for(int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] + d[a[i]][5];
	for(int i = 1; i <= m; i++) dp[0][i] = dp[0][i - 1] + d[5][b[i]];
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			dp[i][j] = max(dp[i - 1][j - 1] + d[a[i]][b[j]], max(dp[i - 1][j] + d[a[i]][5], dp[i][j - 1] + d[5][b[j]]));
	
	cout << dp[n][m];
	
	return 0;
}

//7 AGTGATG
//5 GTTAG
//
//14
