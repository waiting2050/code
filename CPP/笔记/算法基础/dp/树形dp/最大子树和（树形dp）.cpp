#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ���峣��NΪͼ�п��ܵ����ڵ�����һЩ����ռ�
const int N = 1e5 + 7;

// dp[i] ��ʾ�Խڵ�iΪ���������е����·����
int dp[N];
// w[i] ��ʾ��i���ڵ��Ȩ��
int w[N];
// g[i] ���ڽӱ���ʾ��ڵ�i���������нڵ�
vector<int> g[N];

// �����������������root�ǵ�ǰ�ڵ㣬pre�����ĸ��ڵ�
void dfs(int root, int pre) 
{
    // ��ʼ��dp[root]Ϊ�ڵ�root�����Ȩ��
    dp[root] = w[root];
    
    // ����������root���ڵĽڵ�ele
    for (auto &ele : g[root]) 
    {
        if (ele == pre) continue; // ���ele�Ǹ��ڵ㣬�������������ظ�����
        dfs(ele, root); // �ݹ�����ӽڵ�
        
        // ����dp[root]�����Ǽ����ӽڵ�ele��dpֵ������һ��Ҫ�ӣ���Ϊ���ܴ��ڸ�Ȩ��
        dp[root] = max(dp[root], dp[root] + dp[ele]);
    }
}

// ����������������ĺ���
void solve() {
    int n; cin >> n; // ����ڵ�����n
    
    // ����ÿ���ڵ��Ȩ��
    for (int i = 1; i <= n; i++) cin >> w[i];
    
    // �������Ϣ����������ͼ
    for (int i = 1; i < n; i++) 
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    // �ӽڵ�1��ʼִ�������������,��2��3...��ʼҲ���ԡ����ڵ�����Ϊ-1����ֹ��������Ϊ1Ϊ������û�и��ڵ㣬������һ�������ܻ���ֵĵ������ڵ㣩
    dfs(1, -1);
    
    // ��������������dpֵ�е����ֵ
    cout << *max_element(dp + 1, dp + n + 1) << '\n';
    
    // ����ȫ�ֱ������Ա㴦����һ����������
    for (int i = 1; i <= n; i++) 
    {
        dp[i] = w[i] = 0; 
        g[i].clear(); 
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// 1
// 5
// -5 -2 -3 10 10
// 1 2
// 1 3
// 3 4
// 3 5
// 
// 17
