// 建树，dp[i][j]表示将arr[i~j]拆为二叉树的最小代价
// 当len为1，dp[i][j] = 0（叶子节点）；否则，dp[i][j]=min(dp[i][k]+dp[k + 1][j]+val[i][k]*val[k + 1][j])，非叶子节点
// val[i][j]维护arr[i~j]的最大值

const int INF = 0x3f3f3f3f;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector dp(n + 7, vector<int> (n + 7, INF));
        vector val(n + 7, vector<int> (n + 7));
        arr.insert(arr.begin(), 0);

        for(int len = 1; len <= n; ++len)
        {
            for(int i = 1, j = i + len - 1; j <= n; ++i, ++j)
            {
                if(len == 1) val[i][j] = arr[i], dp[i][j] = 0;
                else val[i][j] = max(val[i][j - 1], arr[j]);

                for(int k = i; k < j; ++k)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + val[i][k] * val[k + 1][j]);
            }
        }

        return dp[1][n];
    }
};

// 示例 1：
// 输入：arr = [6,2,4]
// 输出：32
// 解释：有两种可能的树，第一种的非叶节点的总和为 36 ，第二种非叶节点的总和为 32 。 


// 示例 2：
// 输入：arr = [4,11]
// 输出：44