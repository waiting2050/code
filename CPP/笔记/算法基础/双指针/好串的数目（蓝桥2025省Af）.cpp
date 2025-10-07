// Problem: Luogu P12143
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P12143
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string a; cin >> a;
	a = " " + a;
	int n = a.size() - 1;
	
	int brk = 0;
	ll ans = 1;//����Ϊ1�ĵ�һ���Ӵ����� 
	for(int l = 1, r = 1; r <= n; r++)//ö��ÿһ���Ҷ˵� 
	{
		//if(r == 1) continue;//���� 
		if(a[r - 1] != a[r] && a[r - 1] + 1 != a[r]) brk++;//�ж϶ϵ� 
		while(brk > 1)//һ���ϵ���࣬��Ҫ�����������ƣ���취�õ���ҵĺϷ������� 
		{
			l++;
			if(a[l] != a[l - 1] && a[l] - 1 != a[l - 1]) brk--;
		}
		
		ans += r - l + 1;//�����൱��ͳ�ƺϷ���˵������ÿ���Ϸ���˵㶼�����뵱ǰ�Ҷ˵㹹��һ����Ч�Ӵ������������Լ�Ϊ���Ҷ˵�����䣩 
	}
	
	cout << ans;
	
	return 0;
}

//12258
//
//12
//
//
//97856
//
//13
