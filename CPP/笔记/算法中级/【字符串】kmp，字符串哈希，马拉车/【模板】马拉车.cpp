#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 1e7 + 7;

string s(N << 1, '\0'); //���븳��ֵ����С����Ϊ2*n+3 
int p[N << 1]; //P 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n >> s;
	s.insert(s.begin(), '?');
	
	for(int i = 2 * n + 1; i >= 1; i--)
	{
		if(i & 1) s[i] = '#'; //������������� 
		else s[i] = s[i >> 1]; //ż����ԭ�ַ��� 
	}
	s[0] = '&', s[2 * n + 2] = '^'; //���߷Ų�ͬ�������ַ� 
	
	int C = 0, R = 0; //C�ǻ������ģ� R���ұ߽� 
	for(int i = 1; i <= 2 * n + 1; i++) //R��඼�Ǹ��¹��ģ��Ҳ���δ֪�� 
	{
		p[i] = i < R ? min(p[2 * C - i], R - i) : 1; //������Ϣ
		while(s[i - p[i]] == s[i + p[i]]) p[i]++; //������չ
		if(i + p[i] > R) C = i, R = i + p[i]; //�������ұ߽磬����������߽磨˭�ܹܵ����ұߣ�����ΪC�� 
	}
	
	int ans = 0;
	for(int i = 1; i <= 2 * n + 1; i++) ans =  max(ans, p[i] - 1); //p[i]-1��Ϊ�޸�ǰ���Ե�ǰ�ַ�Ϊ���ĵĻ��Ĵ����� 
	
	cout << ans;
	
	return 0;
}

// 4
// abaa
// 
// 3
