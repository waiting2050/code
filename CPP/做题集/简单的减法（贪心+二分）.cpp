#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;
ll a[N];

bool check(ll mid, int n, int k)
{
	ll sum = 0;
	for(int i = 1; i <= n; i++)
		sum += min(mid, a[i]);
		
	return sum >= k * mid;
//	����ĳ���������⣺
//	����n=5,k=3,mid=2,������ǹ���ÿ�δ������ǹ�����һ���������Σ�
//	���������ǹ���Ϊ0����ô��ʹʣ�µ����������ܶ�Ҳ�޷�����������
//	��ʱ min(mid, a[i]),���� sum=2*mid������k(k=3)*mid ������check
//	�����ĳ�����ǳ����� 
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	ll l = 0, r = 2e14 + 7;
	while(l + 1 ^ r)
	{
		ll mid = (l + r) >> 1;
		if(check(mid, n, k)) l = mid;
		else r = mid;
	}
	
	cout << l << '\n';
	
	return 0;
}

// 5 3
// 2 8 2 3 9
// 
// 7
