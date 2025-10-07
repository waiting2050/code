//dp[i][k]��ʾ����i��β��ɾ��k�εõ������� 

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

//���룺arr = [-1,-1,-1,-1]
//�����-1
//
//
//���룺arr = [1,-2,-2,3]
//�����3
//
//
//���룺arr = [1,-2,0,3]
//�����4
