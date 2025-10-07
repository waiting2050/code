#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e6 + 7;
const int N = 107;
ll dp[N][N], a[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	
	// ����ÿ�ֻ������������������
	for(int i = 1; i <= n; i++) cin >> a[i];
	
    // ��ʼ��dp���飬dp[0][0]��ʾû��ѡ���κλ����������һ�ַ�������ʲô��������
	dp[0][0] = 1;
	
    // ��̬�滮���
	for(int i = 1; i <= n; i++)// ����ÿһ�໨
		for(int j = 0; j <= m; j++)// ���Է��ò�ͬ�����Ļ�
			for(int k = 0; k <= j && k <= a[i]; k++)// ����k����ǰ���͵Ļ�
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod; // �ۼ����п��ܵķ��������Խ��ȡģ
	
    // ������մ𰸣���ʹ����������Ļ�ǡ�÷���m��ķ�����
	cout << dp[n][m];

	return 0;
}

// 2 4
// 3 2
// 
// 2
