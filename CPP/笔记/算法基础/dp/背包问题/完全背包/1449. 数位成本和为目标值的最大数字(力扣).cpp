// 二维版本

// 跑两次循环，第一次循环找出字符串最大长度，第二次找出最大长度下的字符串
// 第一次循环用完全背包的模板即可，第二次要用到记录路径的数组
class Solution
{
public:
    string largestNumber(vector<int> &cost, int target)
    {
        vector<vector<int>> dp(10, vector<int>(target + 1, INT_MIN));
        vector<vector<int>> from(10, vector<int>(target + 1));
        dp[0][0] = 0;
        for (int i = 0; i < 9; ++i) // 完全背包的更新是先从上一行同位置转移，再从同一行前面转移过来
        {                           // 因此对于不选择的情况，直接将路径记录为本身j，意思就是该从上一行转移了
            int c = cost[i];
            for (int j = 0; j <= target; ++j)
            {
                if (j < c)
                {
                    dp[i + 1][j] = dp[i][j];
                    from[i + 1][j] = j; 
                }
                else
                {
                    if (dp[i][j] > dp[i + 1][j - c] + 1)
                    {
                        dp[i + 1][j] = dp[i][j];
                        from[i + 1][j] = j;
                    }
                    else
                    {
                        dp[i + 1][j] = dp[i + 1][j - c] + 1;
                        from[i + 1][j] = j - c;
                    }
                }
            }
        }
        if (dp[9][target] < 0)
        {
            return "0";
        }
        string ans;
        int i = 9, j = target;
        while (i > 0)
        {
            if (j == from[i][j]) //路径未变，说明从上一行转移
            {
                --i;
            }
            else //否则一定是从当前行转移
            {
                ans += '0' + i; //注意插入顺序
                j = from[i][j];
            }
        }
        return ans;
    }
};


// 空间优化版本
const int INF = 0x7f7f7f7f;

class Solution
{
public:
    string largestNumber(vector<int> &cost, int target)
    {
        int n = cost.size();
        cost.resize(n + 1);
        for (int i = n - 1; i >= 0; i--) cost[i + 1] = cost[i];
        vector<int> dp(target + 7, -INF);

        dp[0] = 0;
        for (int i = n; i >= 1; i--)
        {
            for (int j = cost[i]; j <= target; j++)
            {
                dp[j] = max(dp[j], dp[j - cost[i]] + 1);
            }
        }
        if (dp[target] < 0) return "0";

        string ans;
        for (int i = 9, j = target; i >= 1; i--) //这个地方要从大到小，
        {
            for (int c = cost[i]; j >= c && dp[j] == dp[j - c] + 1; j -= c) // dp[j] == dp[j - c] + 1是路径转移的关键判断
            {
                ans += '0' + i;
            }
        }

        return ans;
    }
};