// Problem: AT ABC418 D
// Contest: AtCoder - AtCoder Beginner Contest 418
// URL: https://atcoder.jp/contests/abc418/tasks/abc418_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//���������ַ��������еĲ�������ʱ��Ѱ�Ҳ�����������ǰ�󱣳ֲ����ĳ��ֵ���ķ�����������Ч��
//00->1,0��2��01/10->,0û�٣�11->1,0û�٣�ͨ���۲췢��0����������ż���ǲ����
//���Կ��Եó����ۣ�����0�ĸ���Ϊż�����Ӵ����������� 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int dp[N][2]; //dp[i][0]��ʾ�Ե�iλ��β��0�ĸ���Ϊż���������Ӵ�����
		      //�������i��β�Ǵ�1��i��2��i��3��i�ȵȣ�������ָ��1��i 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	string s; cin >> s;
	s = "?" + s;
	
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == '0')
		{
			dp[i][0] = dp[i - 1][1]; //��ǰλ�õ�0��ʹ0����+1��֮ǰ0���������ϱ�ż���������ǰ���������ڣ�����i��i��ô0������Ϊ���� 
			dp[i][1] = dp[i - 1][0] + 1;
		}
		else
		{
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = dp[i - 1][1];
		}
	}
	
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans += dp[i][0]; //������ÿ��λ�ý�β��0��ż����������� 
	
	cout << ans;
	
	return 0;
}

//3
//110
//
//3
//
//
//30
//011011100101110111100010011010
//
//225
