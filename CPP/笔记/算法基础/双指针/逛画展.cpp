#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 7, M = 2e3 + 7;
int a[N], c[M];//�洢�������ݺͼ��� 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	//l,r��Ϊ˫ָ�룬ll,rr�洢�𰸣�cnt��dis��Ϊ�ж����� 
	int l = 0, r = 1, ll, rr, cnt = 0, dis = 1e9;
	while(r <= n)
	{
		c[a[r]]++;//ÿ���ƶ���r���ü��������� 
		if(c[a[r]] == 1) cnt++;//����¼���һ�����ң�����cnt++�����ֻ�ǳ��ֶ��ͬ������Ʒ�Ͳ��� 
		
		while(cnt == m)//��ѭ�������Ժ�cntһ����С��m�� 
		{
			c[a[l]]--;//���������Ժ�������˵����ƣ�����û�и�����Ĵ� 
			if(!c[a[l]]) cnt--;//�����˵��ƶ�����һ������û����Ʒչ��������cnt-- 
			if(r - l + 1 < dis)//������������������䳤�ȸ��̵�������͸��£�ע�ⲻҪȡ�ȣ�������˵�δ������ǰ��ģ� 
			{
				ll = l, rr = r;
				dis = rr - ll + 1;
			}
			l++;
		}
		r++;//ֻ�����Ҽ�������Ѱ�ҷ�Χ 
	}
	
	cout << ll << ' ' << rr;
	
	return 0;
}

//12 5
//2 5 3 1 3 2 4 1 1 5 4 3
//
//2 7
