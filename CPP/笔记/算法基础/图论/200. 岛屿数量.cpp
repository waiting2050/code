// 典型的flood fill算法

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        auto dfs = [&](this auto&& dfs, int x, int y)
        {
            if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != '1') return;

            grid[x][y] = '2'; // 注意这里需要先染色再拓展，否则会死循环
            dfs(x, y + 1);
            dfs(x, y - 1);
            dfs(x - 1, y);
            dfs(x + 1, y);
        };

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};

// 示例 1：
// 输入：grid = [
//   ['1','1','1','1','0'],
//   ['1','1','0','1','0'],
//   ['1','1','0','0','0'],
//   ['0','0','0','0','0']
// ]
// 输出：1


// 示例 2：
// 输入：grid = [
//   ['1','1','0','0','0'],
//   ['1','1','0','0','0'],
//   ['0','0','1','0','0'],
//   ['0','0','0','1','1']
// ]
// 输出：3