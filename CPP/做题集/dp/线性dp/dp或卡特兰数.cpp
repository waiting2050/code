// Problem: 
//     P1044 [NOIP2003 普及组] 栈
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1044
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 27;
int dp[N][N];//dp[i][j] i代表队列，j代表栈

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 0; i <= n; i++) dp[0][i] = 1;//当队列里没有元素，只有出栈一种方案
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(j == 0) dp[i][j] = dp[i - 1][j + 1];
			else dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
		}
	}
	
	cout << dp[n][0];
	
	return 0;
}
//以下为卡特兰数解法：h(n)=c(2n,n)-c(2n,n-1) (n=0,1,2,...)
#include<cstdio>
#define siz 20
using namespace std;

int n;
int c[siz * 2][siz];

int main() 
{
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) c[i][1] = c[i][i] = 1;

    for (int i = 3; i <= 2 * n; i++)
        for (int j = 2; j < i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];

    printf("%d", c[2 * n][n] - c[2 * n][n - 1]);

    return 0;
}
