class Solution {
public:
    string decodeString(string& s) {
        int dep = 0;

        auto dfs = [&](this auto&& dfs) -> string
        {
            string res;
            int times = 0;

            while(dep < s.size())
            {
                char c = s[dep];

                if(isdigit(c)) times = times * 10 + c - '0';
                else if(c == '[')
                {
                    dep++;
                    string in = dfs();
                    while(times > 0) 
                    {
                        res += in;
                        times--;
                    }
                }
                else if(c ==']') return res;
                else res += c;

                dep++;
            }

            return res;
        };

        return dfs();
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