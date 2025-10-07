#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;

int a[N], maxq[N], minq[N];

//˼·���������һ�����䣬���㼫�������������䣨�������������죩���ᷢ�ּ���ֻ�����򲻱䣬�����С��
//���ǵó����ۣ�������䲻�Ϸ������䳬����Ҳ���Ϸ������Կ�����˫ָ�����������䡣
//�Ƚ����Ҷ˵���ڿ�ͷ���±�Ϊ1���������������Ҷ˵㲢��ͳ�ƺϷ�����������ֱ�����Ϸ�ʱ���ƶ���˵㡣
//���ʱ��������ֵ�Ƕ�̬�仯�ģ������õ���������ά��������ֵ�� 
 

void solve()
{
	int n, m; cin >>n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	ll ans = 0;
	int l = 1, mihh = 1, mitt = 0, mxhh = 1, mxtt = 0;
	for(int r = 1; r <= n; r++)//l,r��˫ָ�벿�� 
	{
		while(mihh <= mitt && a[r] <= a[minq[mitt]]) mitt--;//��β�Ϸ��� 
		minq[++mitt] =r;
		
		while(mxhh <= mxtt && a[r] >= a[maxq[mxtt]]) mxtt--;
		maxq[++mxtt] = r;
		
		while(mihh <= mitt && mxhh <= mxtt && a[maxq[mxhh]] - a[minq[mihh]] > m)
		{
			l++;
			
			while(mihh <= mitt && minq[mihh] < l) mihh++;//��ͷ�Ϸ��� 
			while(mxhh <= mxtt && maxq[mxhh] < l) mxhh++;
		}
		
		ans += r - l + 1;
	}
	
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}

//2
//5 2
//1 3 2 5 9
//6 3
//1 1 4 5 1 4
//
//8
//11
