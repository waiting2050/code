//这道题反向更新dp更简单，假如正向更新，那么骑士的初始血量是未知的，且到每个点的剩余最大生命值和这条路上的
//历史最低点是非常重要的两个参数，而且这两个参数的更新逻辑不是一样的。简单来讲，也许你当前生命值是比另一个点
//高的，但是在这条路上你的血量低点更低，如果要正向，可以先用二分枚举初始生命值，再用dp判断能否到达
//但若是反向，公主的初始生命值是可以轻松确定的，然后把逻辑取反，减生命值变成加（要求提高） 

const int INF = 0x7f7f7f7f;

class Solution 
{
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n + 7, vector<int> (m + 7, INF));

        dp[n - 1][m - 1] = dungeon[n - 1][m - 1] > 0 ? 1 : 1 - dungeon[n - 1][m - 1];
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                if(i == n - 1 && j == m - 1) continue;
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
            }
        }

        return dp[0][0];
    }
};

//输入：dungeon = [[0]]
//输出：1
//
//输入：dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
//输出：7
