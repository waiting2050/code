#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7;
int pre[N << 1];

int find(int x)
{
	return pre[x] = (pre[x] == x ? x : find(pre[x]));
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n << 1; i++) pre[i] = i;
	
	while(m--)
	{
		char op; cin >> op;
		int p, q; cin >> p >> q;
		
		// 1.���Ǳ�����1---nΪ����������ѭ���л���Ϊn+1--2nΪ������ʧ�������������ֻ��pre[find(p+n)]=find(q),����pre[find(p)]=find(q+n) 
		// 2.��������������ѣ����ǲ���Ҫʹ���ǵķ�������, 2��3�ĵ��ˣ�4��5�ĵ��ˣ�3��4�����ѣ������ǲ���˵2��5������
		//���Բ���дpre[find(p+n)]=pre[find(q+n)] 
		if(op == 'E') 
		{
			pre[find(p + n)] = find(q);
			pre[find(q + n)] = find(p);
		}
		else pre[find(p)] = find(q);
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(pre[i] == i) cnt++;
		
	cout << cnt;
	
	return 0;
}

// 6
// 4
// E 1 4
// F 3 5
// F 4 6
// E 1 2
// 
// 3
