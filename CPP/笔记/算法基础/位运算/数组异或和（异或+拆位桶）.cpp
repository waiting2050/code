// Problem: CF 2094 E
// Contest: Codeforces - Codeforces Round 1017 (Div. 4)
// URL: https://codeforces.com/contest/2094/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//1.��ȻҪ��λ��Ԥ�����λ����һ��Ͱȥ��¼30��λ��ÿ��λ�м���1����СΪ30����Ϊ���2^30��
//2.Ԥ�����Ժ�ö��ÿһ��k��k��[1,n]��Ȼ���ak��ÿһλȥ��飬
//�����ǰλΪ1������Ժ������Ϊ0��λ���1�����Ǽ���(��ǰλ��λȨ*0�ĸ���)�� ��֮������λȨ*1�ĸ��� 

const int N = 2e5 + 7;

int a[N];

void solve()
{
	vector<int>c(32, 0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for(int j = 0; j < 30; j++)
		{
			int mask = a[i] >> j & 1;
			if(mask) c[j]++;
		}
	}
	
	// for(auto& y : c) cout << y << ' ';
	// cout << '\n';
	
	ll mx = 0;
	for(int i = 1; i <= n; i++)
	{
		ll ans = 0;
		for(int j = 0; j < 30; j++)
		{
			int mask = a[i] >> j & 1;
			ll k = 1 << j;
			//cout << k << ' ';
			ans += (mask ? k * (n - c[j]) : k * c[j]);
		}
		mx = max(mx, ans);
	}
	
	cout << mx << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

//5
//3
//18 18 18
//5
//1 2 4 8 16
//5
//8 13 4 5 15
//6
//625 676 729 784 841 900
//1
//1
//
//0
//79
//37
//1555
//0
