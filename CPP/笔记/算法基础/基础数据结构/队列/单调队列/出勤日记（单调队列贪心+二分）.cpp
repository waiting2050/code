// Problem: Luogu P12000
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P12000
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 7;

struct P
{
	ll hl, summ;//���ʣ���Ǯ��
} dq[N];
ll a[N], n;//���� 
ll b[N];//���� 

//check˼·���Զ��׼���Ҫ̰�ģ��ڻ��ʸߵ�λ�þ����ܶһ���������ɲ���Ҫ�󲻵ò���û��ô�õ�λ�öһ��������������ö�ٺ���������Ų��ԣ�
//�ǲ����������ö�٣����ڵ�i��λ������Ҫx����Ϸ�ң��Ǿ������ҳ�������ߵ�Ȼ��һ��������ٶһ�һ�㣬��Ϊ֮������и��ߵĻ��ʣ���ͬʱע��
//���ʵĸ��������ߵģ�ÿ����һ���Ҷ˵��Ҫ����һ�Σ�����ô�������оͷ������Ҫ�󣬲���ע������һ�����ϵ�Ǯ�������һ��������Ļ�Ҫ�һ��ʵĴθߵ㡣 

bool check(ll mid)
{
	int hh = 1, tt = 0;
	ll sum = 0, supg = 0, usem = 0;//��ǰ����Ǯ����ʣ�����Ϸ�������Ѿ����˶���Ǯ
	for(int i = 1; i <= n; i++)//�൱��ö���Ҷ˵㣬������֮ǰ���е���ѵĿɹ��һ������ 
	{
		sum += b[i];
		
		//��ͷ�ĺϷ�����summά������Ϊû����ȷ�����䣬ֻ�е�Ǯ���ò�������һ�����ʱ��Ž��䵯�� 
		//���е������Ǵ��Ҷ˵������������������˵㲻�Ϸ���ûǮ����Ϸ�ң�ʱ���� 
		while(tt >= hh && a[i] >= dq[tt].hl) tt--;//��β�ĺϷ���
		dq[++tt] = (P){a[i], sum};
		
		if(supg < mid) 
		{
			//�õ�����������ά���������ֵ�����������ڻ�����ߵ�һ���Ǯ����֮��ſ����ڴθߵ�һ�
			//��Ϊ��ȷ��֮��᲻���и��ߵĻ��ʣ�����ÿ�ξ����ٶһ� 
			while(tt >= hh && supg < mid)//�����зǿ�����Ϸ�Ҳ���mid������Ϊ�п���Ҫ��ζһ��� 
			{
				ll supm = dq[hh].summ - usem;//�������hh��ʹ�õ�Ǯ
				ll needg = mid - supg;//��Ҫ����Ϸ����
				ll needm = min(supm, ((needg + dq[hh].hl - 1 )/ dq[hh].hl));//��Ҫ��Ǯ����С���ɣ�+dq[hh].hl-1�൱��ceil�����Ϸ�ĸ-1�� 
				
				usem += needm;
				supg += needm * dq[hh].hl;
				if(!(supm - needm)) hh++;
			}
			if(supg < mid) return false;//������п��ˣ����޿ɻ����Ҳ�����mid��Ҫ��ʱ���ط� 
		}
		supg -= mid;
	}
	
	return true;
}

void solve()
{
	cin >> n;
	
	ll mx = 0, lim = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]);
	for(int i = 1; i <= n; i++) cin >> b[i], lim += b[i] * mx;
	
	ll l = 0, r = lim / n + 1;//ע��������Ҫ��ll������ᱬint 
	while(l + 1 != r)
	{
		ll mid = (l + r) >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	
	cout << l << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}

// 3
// 5
// 1 2 3 4 5
// 5 4 3 2 1
// 5
// 1 1 1 1 1
// 2 3 4 5 6
// 9
// 9 9 8 2 4 4 3 5 3
// 10 10 10 10 10 10 10 10 10
// 
// 5
// 2
// 55
