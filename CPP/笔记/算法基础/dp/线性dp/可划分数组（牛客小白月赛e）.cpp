// Problem: �ɻ�������
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/105825/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e3 + 7;

int a[N], dp[N], l[N], r[N];//dp[i]Ϊ��iΪ��β����໮�ֶ��ٶ�

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	memset(r, 0x3f, sizeof(r));
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) dp[i] = -2e9;
	
	for(int i = 1; i <= n; i++)//��ÿһ��i����������ߺ��ұ�����Ҫ������������� 
	//ps:���һ������[l,r]�Ϸ�����ô��������ÿһ�����li>=l,ri<=r 
	{
		for(int j = i + 1; j <= n; j++)
			if(__gcd(a[i], a[j]) ^ 1) r[i] = min(r[i], j);
		for(int j = i - 1; j >= 1; j--)
			if(__gcd(a[i], a[j]) ^ 1) l[i] = max(l[i], j);
	}
	
	//for(int i = 1; i <= n; i++) cout << l[i] << ' ' << r[i] << '\n';
	dp[0] = 0;
	for(int i = 1; i <= n; i++)//i�������Ҷ˵㣬j��������˵�
	{
		int lft = i;//lft��[j,i]���ÿһ���㣬ֻҪlft�Ϸ����Ϳ��Ը��´� 
		for(int j = i; j >= 1; j--)//Ҫ��i��ʼ����ΪҪ�ȸ�����˵�lftΪl[i](һ��ʼj==i)
		{
			if(r[j] > i) lft = min(lft, l[j]);//����ұ߲��Ϸ�����ô���jֻ��������������ɶԵġ�
			//����min̰�ģ�lftһ����������������˵�������һ��������ֻҪlft�Ϸ�����ô���ж˵㶼�ǺϷ��ġ�
			 
			if(lft >= j) dp[i] = max(dp[i], dp[j - 1] + 1);//�����ߺϷ���dpҪô�̳У�Ҫô������˵��β��dp+1 
		}
	}
	
	cout << max(dp[n], -1);
	
	return 0;
}

