//dp[i][k]表示到以i结尾，删除k次得到的最大和 

class Solution 
{
public:
    int maximumSum(vector<int>& arr) 
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 7, vector<int> (2));
        arr.insert(arr.begin(), 0);

        dp[1][0] = arr[1];
        int mx = arr[1];
        for(int i = 2; i <= n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], 0) + arr[i];
            dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);
            mx = max({mx, dp[i][1], dp[i][0]});
        }

        return mx;
    }
};

//输入：arr = [-1,-1,-1,-1]
//输出：-1
//
//
//输入：arr = [1,-2,-2,3]
//输出：3
//
//
//输入：arr = [1,-2,0,3]
//输出：4
