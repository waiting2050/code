//����ⷴ�����dp���򵥣�����������£���ô��ʿ�ĳ�ʼѪ����δ֪�ģ��ҵ�ÿ�����ʣ���������ֵ������·�ϵ�
//��ʷ��͵��Ƿǳ���Ҫ���������������������������ĸ����߼�����һ���ġ���������Ҳ���㵱ǰ����ֵ�Ǳ���һ����
//�ߵģ�����������·�����Ѫ���͵���ͣ����Ҫ���򣬿������ö���ö�ٳ�ʼ����ֵ������dp�ж��ܷ񵽴�
//�����Ƿ��򣬹����ĳ�ʼ����ֵ�ǿ�������ȷ���ģ�Ȼ����߼�ȡ����������ֵ��ɼӣ�Ҫ����ߣ� 

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

//���룺dungeon = [[0]]
//�����1
//
//���룺dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
//�����7
