#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e4 + 7;
int pre[3 * N];

//find�����ʵ������ߣ�find(a)==find(b+n)��˼��b���Գ�a��find(a)==find(b)��ʾ������ͬ������ȼۣ� 
int find(int x)
{
	return pre[x] = (pre[x] == x ? x : find(pre[x]));
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, k; cin >> n >> k;
	//3n��ʾ��������A��B��C���趨B��A��C��B��A��C
	//ps������ͬ����֮��ʹ��==���жϲ�ʳ��ϵ����ͬ����ʹ��==���ж��Ѻù�ϵ�� 
	for(int i = 1; i <= n * 3; i++) pre[i] = i;
	
	int cnt = 0;
	while(k--)
	{
		int op, x, y; cin >> op >> x >> y;
		if(x > n || y > n)
		{
			cnt++;
			continue;
		}
		
		if(op == 1)//����������ϲ�Ϊͬ�� 
		{
			//���x���ܱ�y�Ե�������y���ܱ�x�Ե� 
			if(find(x) == find(y + n) || find(y) == find(x + n)) cnt++;
			else
			{
				//�ϲ�Ϊͬ�� 
				pre[find(x)] = find(y);
				pre[find(x + n)] = find(y + n);
				pre[find(x + 2 * n)] = find(y + 2 * n);
			}
		}
		else//���Ӳ�ʳ��ϵ ��x��y 
		{
			//�����������ȼۣ�����y���Գ�x 
			if(find(x) == find(y) || find(y + n) == find(x)) cnt++;
			else
			{
				//���Ӳ�ʳ��ϵ 
				pre[find(x + n)] = find(y);
				pre[find(x + 2 * n)] = find(y + n);
				pre[find(x)] = find(y + 2 * n);
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}

// 100 7
// 1 101 1
// 2 1 2
// 2 2 3
// 2 3 3
// 1 1 3
// 2 3 1
// 1 5 5
// 
// 
// 3
