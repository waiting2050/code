#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;

ll a[N], b[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	ll n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	sort(a + 1, a + 1 + n);//����̰�ĺ������뵽 
	
	ll ans = 0;
	for(ll i = 1; i <= n; i++)//��ʱa��b���ǹ̶��˵ģ�����b������ģ����Զ�a���֡���ǰ��b����С��a��Ԫ�أ��൱�ڴӺ���a�������b��Ԫ�� 
		ans += n - (upper_bound(a + i, a + 1 + n, b[i]) - a) + 1;//ע�������Ǵ�a+i��ʼ���Ǵ�a+1��ʼ 
	
	cout << ans;
	
	return 0;
}

//5
//3 1 4 1 5
//2 7 1 8 3
//
//7
