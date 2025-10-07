// Problem: Luogu P2196
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2196
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 27;

//d��¼��ͨ�ԣ���i��j��û��·��dp[i]��ʾ��iΪ����������õĵ�������a��¼��������rem��ʾ��ǰ�ڵ��ǰ���ڵ���˭�� 
int d[N][N], dp[N], a[N], rem[N];

void print(int x)//x�ǵ�ǰ�ڵ� 
{
	if(!rem[x])//���ǰ���ڵ�Ϊ0���ʹ���������ڵ㷶ΧΪ[1,n] 
	{
		cout << x;
		return;
	}
	
	print(rem[x]);//�ݹ����ǰһ���ڵ� 
	cout << ' ' << x;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i < n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			cin >> d[i][j];
		}
	}
	
	int ans = 0, lim = 0;
	for(int i = 1; i <= n; i++)//ö���յ� 
	{
		dp[i] = a[i];//��ʼ����ֻѡ��ǰ�ڵ� 
		for(int j = 1; j <= i; j++)//ö����㣬j��i��ǰ�����н������������������������ 
		{
			if(d[j][i] && dp[i] < dp[j] + a[i])//ֻҪ������յ���ͨ�����ҵ�ǰ�������ţ��͸��´𰸲���¼·�� 
			{
				dp[i] = dp[j] + a[i];
				rem[i] = j;
			}
		}
		
		if(dp[i] > ans) 
		{
			ans = dp[i];
			lim = i;//lim��¼����һ���ڵ� 
		}
	}
	
	print(lim);//�ݹ���� 
	cout << '\n';
	
	cout << ans;
	
	return 0;
}

//5
//10 8 4 7 6
//1 1 1 0
//0 0 0
//1 1
//1
//
//1 3 4 5
//27
//
//
//
//3
//10 20 5
//0 1
//0
//
//2
//20
