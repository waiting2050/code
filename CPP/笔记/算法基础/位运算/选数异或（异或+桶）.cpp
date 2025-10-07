#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//��Ҫ���ʣ�a^b=x => a^x=b 

const int N = 1e5 + 7;

ll d[N];//�������������������������(a,b)(Ĭ��a<b)��dΪ[1,n]������������a�±������Ǹ��±� 
//�����������1 2 3 4��d[1]=0(ֻ��1����������),d[2]=0(1,2��򲻵���x),d[3]=2(2^3=x��������2���±���2)��d[4]=2(�����������ԣ��̳���һ������λ�ö���) 
map<ll, ll> mp;//��Ϊ��ϣ��洢a^x=b�е�b���һ�γ��ֵ�λ�ã����b��γ��֣���Ȼλ��Խ����Խ�ã� 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	ll n, m, x; cin >> n >> m >> x;
	for(int i = 1; i <= n; i++)
	{
		ll y; cin >> y;
		mp[y] = i;
		d[i] = max(d[i - 1], mp[y ^ x]);//�ǵ�ǰ�����ģ�����У����û���֮ǰ�� 
	}
	
	while(m--)
	{
		int l, r; cin >> l >> r;
		if(d[r] >= l) cout << "yes\n";
		else cout << "no\n";
	}
	
	return 0;
}

//4 4 1
//1 2 3 4
//1 4
//1 2
//2 3
//3 3
//
//yes
//no
//yes
//no
