// Problem: CF 2137 F
// Contest: Codeforces - Codeforces Round 1047 (Div. 3)
// URL: https://codeforces.com/contest/2137/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//�����÷ֳ�����������ǡ�1.a[i]==b[i]����ʱ���丳ֵ��z[i]��z[i]һ���ܶԴ𰸲������ס�
//2.a[i]>b[i],λ��i֮ǰ�������j,ʹa[j]>a[i]��������ǰ׺�����ͬ��3. a[i]<b[i]��λ��i֮ǰ�������j,ʹa[j]>b[i]��������ǰ׺�����ͬ 
//�������ʱ�������ù��׷�����Ҫһ���ܿ�����ĳ�����һ����ĳ����ֵ������ݽṹ�����������st���߶�������״����ȣ���������ѡ���˵���ջ+���� 
//��ΪҪͬʱ����a[i],b[i]�����ȵ���ջ���Ա�֤����a[i]�������ټ��Ͼ��е����Կ���ʹ�ö��ֿ��Կ��ٴ���b[i] 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 7;

int a[N], b[N], stk[N];

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n + 1; i++) stk[i] = 0;
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	ll ans = 0;
	int top = 0;
	for(int i = 1; i <= n; i++)
	{
		while(top && a[stk[top]] < a[i]) top--;
		
		if(a[i] == b[i]) ans += i * (n - i + 1ll);
		else
		{
			int mx = max(a[i], b[i]); //��ʵ��a[i]С���Ѿ�pop�ˣ�����ʡ��a[i] 
			
			int l = 0, r = top + 1;
			while(l + 1 ^ r)
			{
				int mid = (l + r) >> 1;
				if(a[stk[mid]] >= mx) l = mid;
				else r = mid;
			}
			
			ans += stk[l] * (n - i + 1ll); //���û�з���������l����0��stk[0]=0 
		}
		
		stk[++top] = i;
	}
	
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

// 6
// 3
// 5 3 1
// 4 2 1
// 5
// 1 2 3 4 5
// 1 2 3 4 5
// 6
// 7 1 12 10 5 8
// 9 2 4 3 6 5
// 1
// 1
// 2
// 6
// 5 1 2 6 3 4
// 3 1 6 5 2 4
// 2
// 2 2
// 1 1
// 
// 5
// 35
// 26
// 0
// 24
// 1
