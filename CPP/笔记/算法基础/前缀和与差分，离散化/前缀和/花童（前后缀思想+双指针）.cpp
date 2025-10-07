// Problem: CF 2106 D
// Contest: Codeforces - Codeforces Round 1020 (Div. 3)
// URL: https://codeforces.com/contest/2106/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//˼·������û�в��뻨���趨����ô��Ȼ������̰�ĵ��뷨��a�������ң�ֻҪ����b��ѡ�񡣵������˲�����������ʱ����԰ѽ�һ�� 
//������a�Ĳ���������b��ɾ��һ�仨����ɾ���Ժ������̰�ĵ�ѡ��m-1�仨����ôȡɾ������С����һ�仨��ֵ���ɡ������������ȥд���Ӷ�O(nm)
//���ʱ����ǰ׺��׺��˼�������Ż�����ÿ��ai�������ڲ����������´���������ƥ�伸�仨���ٴ���������һ�Ρ�
//�������Ժ�a����Ϊǰ�����Σ�ǰ��a��Ӧǰ��b�����Ҳ�ǣ���ֻҪǰ��+���==m-1����ʱ���ٲ���һ�����Ϳ��Դճ�m 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int a[N], b[N], pre[N], suf[N];

void solve()
{
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	
	pre[0] = suf[n + 1] = 0;//����������Ҫ��ʼ�� 
	for(int i = 1, j = 1; j <= m && i <= n; i++)
	{
		if(a[i] >= b[j]) pre[i] = j++;
		else pre[i] = pre[i - 1];
		if(pre[i] == m)
		{
			cout << 0 << '\n';
			return;
		}
	}

	for(int i = n, j = m; i >= 1 && j >= 1; i--)
	{
		if(a[i] >= b[j]) suf[i] = m - j-- + 1;
		else suf[i] = suf[i + 1];
	}
	
	int ans = 2e9;
	for(int i = 0; i <= n; i++)//ע������i��0��ʼ����Ϊsuf��i+1�����i=1��һ��λ�õĺ�׺�ᱻ����
	//��ô��b��һ�����ܴ�a��Զƥ�䲻�ϣ�pre��ʼ��Ϊ0�����Ӻ���ǰsuf�����ڵ�ǰλ��ƥ�䵽m-1�Ŀ��ܱ����� 
		if(pre[i] + suf[i + 1] == m - 1)
			ans = min(ans, b[pre[i] + 1]);
	
	cout << (ans == 2e9 ? -1 : ans) << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

//7
//9 5
//3 5 2 3 3 5 8 1 2
//4 6 2 4 6
//6 3
//1 2 6 8 2 1
//5 4 3
//5 3
//4 3 5 4 3
//7 4 5
//6 3
//8 4 2 1 2 5
//6 1 4
//5 5
//1 2 3 4 5
//5 4 3 2 1
//6 3
//1 2 3 4 5 6
//9 8 7
//5 5
//7 7 6 7 7
//7 7 7 7 7
//
//6
//3
//7
//0
//-1
//-1
//7
