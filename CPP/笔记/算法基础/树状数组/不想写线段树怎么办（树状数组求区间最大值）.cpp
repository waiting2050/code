#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

//һ����̬�����������ֵ������ 

const int N = 2e5 + 7;
const int mod = 1e9 + 7;
int a[N], b[N], mx[N], n;

int lowbit(int x) {return x & -x;}

//������i��β������Ϊlowbit(i)��һ����������ֵ
void update(int i, int x) {for(; i <= n; i += lowbit(i)) mx[i] = max(mx[i], x);}

//���ĺ��� ���ܿ�󲽾ʹ󲽣���Ȼ��С�� 
int query(int l, int r)
{
	int res = 0;
	//ֱ��������[l,r]������� 
	while(l <= r)
	{
		//��start=r-lowbit(i), ���start��l��ߣ���ֻ���r����ߵ�һ���� 
		res = max(res, b[r]);//ע��������b���飬����mx����
		r--;
		
		//���start��l�ұߣ�˵������Ϊlowbit(i)�����䶼��[l,r]���� 
		for(; r - lowbit(r) >= l; r -= lowbit(r))
			res = max(mx[r], res);
	}
	
	return res;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	b[1] = a[1];
	update(1, b[1]);
	
	for(int i = 2; i <= n; i++)
	{
		int l = max(1ll, i - a[i]);
		int temp = query(l, i - 1);//i-1��ע�����俪��
		b[i] = a[i] * temp % mod;
		update(i, b[i]);
	}
	
	for(int i = 1; i <= n; i++) cout << b[i] << ' ';
	
	return 0;
}

