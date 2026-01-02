// 首先对每一个高度，找到左、右两边第一个小于他的，求该高度贡献即可。
// 直接套两次普通单调栈，再遍历一次求ans可以解决。但是可以优化为一次遍历，维护单调递增栈，遍历每个元素，当当前元素比栈顶小
// 弹出栈顶，此时新栈顶元素肯定小于等于原来的栈顶，于是计算原栈顶高度贡献即可。

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // 最后加入一个0，确保栈内元素全部弹出
        int n = heights.size();
        vector<int> stk(n + 7);

        int top = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            while(top && heights[i] < heights[stk[top]])
            {
                int h = heights[stk[top--]];
                int l = top ? stk[top] : -1;
                int r = i;
                ans = max(ans, h * (r - l - 1));
            }
            stk[++top] = i;
        }

        return ans;
    }
};

// 示例 1:
// 输入：heights = [2,1,5,6,2,3]
// 输出：10
// 解释：最大的矩形为图中红色区域，面积为 10


// 示例 2：
// 输入： heights = [2,4]
// 输出： 4