// j=0时，表示不限次数的选择，与122是一个逻辑。而j>=1时可能从无限次选择转移而来。假设不够选择k次，即多选是亏的，
// 那么无限次选择肯定<=k，但返回的是f[n][k][0]，不够k次也会凑够k次；若超过k次，那无限次选择肯定达标，最后答案从f[i][0][0]逐步转移

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        const int INF = 0x3f3f3f3f;
        vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -INF)));
        
        f[0][0][0] = 0;
        
        for (int i = 0; i < n; i++) {
            int p = prices[i];
            // 处理 j=0 的情况（无限次交易）
            f[i + 1][0][0] = max(f[i][0][0], f[i][0][1] + p);
            f[i + 1][0][1] = max(f[i][0][1], f[i][0][0] - p);
            
            // 处理 j>=1 的情况（有限次交易）
            for (int j = 1; j <= k; j++) {
                f[i + 1][j][0] = max(f[i][j][0], f[i][j][1] + p);
                f[i + 1][j][1] = max(f[i][j][1], f[i][j - 1][0] - p);
            }
        }
        
        return f[n][k][0];
    }
};