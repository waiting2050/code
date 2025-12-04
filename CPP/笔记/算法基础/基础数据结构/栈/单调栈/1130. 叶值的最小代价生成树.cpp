// 表面上看是一道树的题目，但是题中要求中序遍历的结果为arr，就是说要保持数组的相对位置，只能合并相邻元素
// 完全可以当成是动态合并数组的题目。代价是由小的乘积求和得到的，想办法让乘积尽可能小，这样对ans的贡献也会尽可能小
// 类似于哈夫曼树。因为只能合并相邻元素，那么对一个山谷元素，与它左右两边较小的合并。可以用单调递减栈维护，确保
// 找到的一定是山谷元素，然后合并，将较大元素入栈，重复过程。最后处理完，栈里面剩下的一定是单调递减的，
// 从栈顶向下依次合并即可。

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<int> stk(n + 7);
        arr.insert(arr.begin(), 0);

        int top = 0, ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            while(top && arr[stk[top]] <= arr[i])
            {
                int y = arr[stk[top--]];
                if(!top || arr[stk[top]] > arr[i]) ans += y * arr[i];
                else ans += y * arr[stk[top]];
            }
            stk[++top] = i;
        }

        while(top >= 2)
        {
            int x = arr[stk[top--]];
            ans += arr[stk[top]] * x;
        }

        return ans;
    }
};

// 示例 1：
// 输入：arr = [6,2,4]
// 输出：32
// 解释：有两种可能的树，第一种的非叶节点的总和为 36 ，第二种非叶节点的总和为 32 。 


// 示例 2：
// 输入：arr = [4,11]
// 输出：44