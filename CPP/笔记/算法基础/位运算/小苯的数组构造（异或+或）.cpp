// Problem: С�������鹹��
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/105623/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//ֻ�ÿ������������x��y�ֱ��ǣ�[0,0],[0,1],[1,0],[1,1]
void solve()
{
	int n, x, y; cin >> n >> x >> y;
	vector<int> ans(n + 1);
	
	if((x & y) != y)//yһ����x���Ӽ����൱������ĳһλx=0��y=1�����
	{
		cout << "NO\n";
		return;
	}
	
	int skip = 1;//������������֣���Χ[1,n]����ΪҪȷ��ans���Ķ�������������̰�ģ��ܷ�1������1��û��skip��ǵĿ��Է�0 
	for(int i = 31; i >= 0; i--)
	{
		int a = (x >> i & 1), b = (y >> i & 1);//����һ��Ҫ&����Ȼȡ�����Ĳ���һλ�� 
		if(!a) continue;//�����жϹ���[0,1]�������жϵ���[0,0]����Ϊ0û��Ҫ�ٲ��� 
		
		bool flag = (a ^ b) ^ (n & 1);//flag==1�൱������[1,0]��nΪż��������[1,1]��nΪ�������������ʱÿһλ����1���� 
		if(flag)
		{
			for(int j = 1; j <= n; j++)
				ans[j] |= 1 << i;
		}
		else//�������ض�λ����0��������1 
		{
			for(int j = 1; j <= n; j++)
			{
				if(j == skip) continue;
				ans[j] |= 1 << i;
			}
			skip++;
		}
	}
	
	int cmp1 = 0, cmp2 = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!ans[i])//�ж�����3 
		{
			cout << "NO\n";
			return;
		}
		
		cmp1 |= ans[i];
		cmp2 ^= ans[i];
	}
	
	if(cmp1 != x || cmp2 != y) cout << "NO\n";//�Ƿ��������1��2 
	else
	{
		cout << "YES\n";
		for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}

//2
//2 3 1
//3 2 3
//
//YES
//2 3
//NO
