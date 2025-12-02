// 记录这一题的主要目的是 起始位置公式： (centerIdx - maxLen) / 2，即本题的pos和mx，通过修改后的字串得到修改前
// 字串的最长回文子串的起点及长度

const int N = 1e3 + 7;

int p[N << 1];

class Solution {
public:
    string longestPalindrome(string& s) {
        int n = s.size();
        string t = s;
        s.insert(s.begin(), '?');
        s.resize(N << 1);

        for(int i = 2 * n + 1; i; --i)
        {
            if(i & 1) s[i] = '#';
            else s[i] = s[i >> 1];
        }
        s[2 * n + 2] = '^';

        int C = 0, R = 0, mx = 0, pos;
        for(int i = 1; i <= 2 * n + 1; ++i)
        {
            p[i] = i < R ? min(p[2 * C - i], R - i) : 1;
            while(s[i - p[i]] == s[i + p[i]]) ++p[i];
            if(i + p[i] > R) C = i, R = i + p[i];

            if(p[i] > mx)
            {
                mx = p[i];
                pos = i;
            }
        }

        return t.substr((pos - mx) / 2, mx - 1);
    }
};

// 示例 1：
// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案。


// 示例 2：
// 输入：s = "cbbd"
// 输出："bb"