#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ����ȫ�ֱ������ڴ洢��������������T����ʱ��/����������Ʒ����M
int T, M;

// dp�������ڶ�̬�滮��dp[i][j]��ʾǰi����Ʒ������Ϊjʱ������ֵ
int dp[2][1007];
// t����洢ÿ����Ʒ�����ʱ�䣨�������
int t[107];
// v����洢ÿ����Ʒ�ļ�ֵ
int v[1007];

// solve�������ڽ��������������ʵ��
void solve()
{
	for(int i = 0; i <= T; i++) dp[0][i] = 0;
	// ����ÿ����Ʒ��ʱ��ͼ�ֵ
	for(int i = 1; i <= M; i++) cin >> t[i] >> v[i];
	
	// ��̬�滮������
	for(int i = 1; i <= M; i++) // ����ÿ����Ʒ
	{
		int y = i & 1;
		for(int j = 0; j <= T; j++) // ����ÿ�ֿ��ܵ���ʱ��/����
		{
			if(j >= t[i]) // �����ǰ����j�㹻���µ�i����Ʒ
				dp[y][j] = max(dp[y ^ 1][j], dp[y ^ 1][j - t[i]] + v[i]); // ��������ֵ
			else 
				dp[y][j] = dp[y ^ 1][j]; // ���򣬲�ѡ�����Ʒ������֮ǰ������ֵ
		}
	}
	
	cout << dp[M & 1][T] << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	while(cin >> T >> M)
	{
		if(T == 0 && M == 0) return 0;		
		solve();
	}
	
	return 0;
}

//�����ǹ����Ż� 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 107, MOD = 1e6 + 7;

int dp[3][N];//ѡ���ڼ��ֻ���ѡ�˶���
int a[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		int y = i & 1;
		
		for(int j = 0; j <= m; j++)
		{
			dp[y][j] = 0;//ע������Ҫ��ʼ������Ϊֻ�����㣬�����ۼӵ���ʽ����ͬ�����ݿ����ظ��ӣ�����1��3�㣩 
			for(int k = 0; k <= j && k <= a[i]; k++)
			{
				dp[y][j] = (dp[y][j] + dp[y ^ 1][j - k]) % MOD;//ͬ������ݿ����ۼ� 
			}
		}
	}
	
	cout << dp[n & 1][m];
	
	return 0;
}

// 42 6
// 1 35
// 25 70
// 59 79
// 65 63
// 46 6
// 28 82
// 962 6
// 43 96
// 37 28
// 5 92
// 54 3
// 83 93
// 17 22
// 0 0
// 
// 117
// 334
