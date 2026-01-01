class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> stk;

        int times = 0;
        string res;
        for(auto& c : s)
        {
            if(isdigit(c)) times = times * 10 + c - '0';
            else if(c == '[')
            {
                stk.push({res, times});
                res = "";
                times = 0;
            }
            else if(c == ']')
            {
                auto [pre, k] = stk.top(); stk.pop();
                while(k--) pre += res; // 注意这里res是当前的，pre是之前的，需要把当前的放在之前后面
                res = move(pre);
            }
            else res += c;
        }

        return res;
    }
};

// 示例 1：
// 输入：s = "3[a]2[bc]"
// 输出："aaabcbc"


// 示例 2：
// 输入：s = "3[a2[c]]"
// 输出："accaccacc"


// 示例 3：
// 输入：s = "2[abc]3[cd]ef"
// 输出："abcabccdcdcdef"


// 示例 4：
// 输入：s = "abc3[cd]xyz"
// 输出："abccdcdcdxyz"