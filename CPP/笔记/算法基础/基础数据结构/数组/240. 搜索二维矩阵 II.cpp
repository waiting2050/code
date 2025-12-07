// 朴素的想法是对每一行用一次二分，复杂度O(nlogm)；但是注意到从右上角开始，左边元素都比它小，下面都比它大，
// 类似与一棵二叉搜索树，于是从右上角开始往下遍历，复杂度o(n+m)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        int i = 0, j = m - 1;
        while(i < n && j >= 0)
        {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }

        return false;
    }
};

// 示例 1：
// 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// 输出：true


// 示例 2：
// 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// 输出：false