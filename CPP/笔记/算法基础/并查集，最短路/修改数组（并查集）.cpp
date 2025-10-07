// Problem: 
//     P8686 [���ű� 2019 ʡ A] �޸�����
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8686
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//����˼·�����������ÿһ�����������ָ���Լ�����ôֱ���������������ָ�������1�����ֵĸ�������ֱ������Լ��ĸ���
//����ָ��ȸ���1�����ֵĸ� 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 7;
int a[N], f[N];

void init(void)
{
	for(int i = 1; i <= N; i++) f[i] = i;//ע������ķ�Χ��N 
}

int find(int x) {return f[x] = (f[x] == x ? x : find(f[x]));}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	
	init();
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++)
	{
		cout << find(a[i]) << ' ';
		f[find(a[i])] = find(find(a[i]) + 1);
	}
	
	return 0;
}

// 5
// 2 1 1 3 4
// 
// 2 1 3 4 5
