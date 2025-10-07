// Problem: Luogu P2758
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2758
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e3 + 7;

int dp[N][N];//dp[i][j]��ʾa��ǰi���ַ���b��ǰj���ַ��������Ĳ�������

//һ�������ֲ�����1.ɾ�� 2.����. 3.�滻 4.���� 
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string a, b; cin >> a >> b;
	a = " " + a;
	b = " " + b;
	
	for(int i = 1; i < a.size(); i++) dp[i][0] = i;//��ʱ��Ҫɾ��i���ַ� 
	for(int j = 1; j < b.size(); j++) dp[0][j] = j;//��ʱ��Ҫ����i���ַ� 
	
	for(int i = 1; i < a.size(); i++)
	{
		for(int j = 1; j < b.size(); j++)
		{
			if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];//�����ǰ�ַ���ȣ���Ȼֱ�Ӽ̳�֮ǰ��״̬��ǰi-1,j-1���������Ĳ���������̣�//Ҳ���ǲ��� 
			else dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1);//����ֱ��ɾ�������룬�滻���п��ǣ� 
		}											//�ٸ����ӣ��滻��ζ�ŵ�ǰa[i]һ������b[j]����ôֻҪǰ���i-1�ܶ�Ӧj-1���� 
	}
	
	cout << dp[a.size() - 1][b.size() - 1];
	
	return 0;
}

//sfdqxbw
//gfdgw
//
//4
