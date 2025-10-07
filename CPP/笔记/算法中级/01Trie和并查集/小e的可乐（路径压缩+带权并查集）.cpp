#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int pre[N], d[N];

int find(int x)
{
	if(pre[x] == x) return x;
	
	int fa = pre[x];
	pre[x] = find(pre[x]);
	d[x] += d[fa]; //�ڵݹ�����Ժ�d[fa]����ȷ��
	
	return pre[x];
}

int mo(int x) {return (x % 2 + 2) % 2;}

//������ʽ�ϲ��Ĳ�����ȥ����getd����Ϊ���е㶼��ֱ���������ڵ㣬ֻҪd����Ϳ����� 
void merge(int x, int y)
{
	int fx = find(x), fy = find(y);
	if(fx == fy) return;
	
	pre[fx] = fy, d[fx] = mo(1 + d[y] - d[x]);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++) pre[i] = i;
	
	while(q--)
	{
		int op, x, y; cin >> op >> x >> y;
		if(op == 1) merge(x, y);
		else
		{
			int fx = find(x), fy = find(y);
			if(fx != fy) cout << "Unknown\n";
			else
			{
				if(mo(d[x] - d[y]) == 1) cout << "NO\n";
				else cout << "YES\n";
			}
		}
	}
	
	return 0;
}

// 5 4
// 1 1 2
// 2 1 2
// 1 2 3
// 2 1 3
// 
// NO
// YES
