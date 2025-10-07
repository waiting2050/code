#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 7;

char s[N], t[N]; //s��Ŀ�괮��t��ģ�崮 
int nxt[N], n, m; //nxt�����ʾǰ׺�ַ����ͺ�׺�ַ���ƥ����ַ������������ٶ�λ������ 

void kmp()
{
	for(int i = 2, j = 0; i <= m; i++) //��nxt 
	{
		while(j && t[j + 1] != t[i]) j = nxt[j];
		if(t[j + 1] == t[i]) j++;
		nxt[i] = j;
	}
	
	for(int i = 1, j = 0; i <= n; i++) //ƥ�������� 
	{
		//t[1, j] == s[i - j, i - 1] 
		while(j && t[j + 1] != s[i]) j = nxt[j]; //�������Ⱦͻ��� 
		if(t[j + 1] == s[i]) j++; //��Ⱦ͸���һ�� 
		if(j == m) cout << i - j + 1 << ' '; //��ȫƥ��ɹ����¼�� 
	}
	cout << '\n';
	
	for(int i = 1; i <= m; i++) cout << nxt[i] << ' ';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> s + 1 >> t + 1;
	n = strlen(s + 1), m = strlen(t + 1);
	s[n + 1] = 's', t[m + 1] = 'b'; //�Լ���һ��ʹ�����ַ���ƥ�� 
	
	kmp();
	
	return 0;
}

// ABCABABA
// ABA
// 
// 4 6
// 0 0 1
