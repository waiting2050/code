// 这道题其实就是找最长的合法区间，只有在某个区间左右括号数量相等，且在任意位置往左看，左括号数量总是>=右括号数量
// 本题代码选择对每一个合法右括号，去记录最靠右的非法位置，那么长度差即为合法区间长度
// 初始时，栈底元素为-1，代表最靠右的非法位置为-1

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> stk(n + 7);

        int top = 0, ans = 0;
        stk[top] = -1;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(') stk[++top] = i;
            else
            {
                top--;
                if(top >= 0) ans = max(ans, i - stk[top]);
                else top = 0, stk[top] = i;
            }
        }

        return ans;
    }
};

// 示例 1：
// 输入：s = "(()"
// 输出：2
// 解释：最长有效括号子串是 "()"


// 示例 2：
// 输入：s = ")()())"
// 输出：4
// 解释：最长有效括号子串是 "()()"


// 示例 3：
// 输入：s = ""
// 输出：0