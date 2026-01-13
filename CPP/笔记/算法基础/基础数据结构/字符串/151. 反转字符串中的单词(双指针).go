// 1、在字符串首尾添加空格，方便处理边界情况
// 2、从后往前遍历字符串，遇到空格就将单词添加到结果中
// 3、返回结果时去掉最后一个空格

// 如果需要O(1)额外空间复杂度的原地解法：
// 1.先把整个字符串反转（"the sky is blue"->"eulb siykseht")
// 2。再逐个反转每个单词（“eulb"->"blue")
// 3.最后原地去除多余空格

func reverseWords(s string) string {
    s = " " + s + " "
    var res strings.Builder
    n := len(s)
    r := n - 1

    for l := n - 2; l >= 0; l-- {
        if s[l] == ' ' {
            if r > l + 1 {
                res.WriteString(s[l+1:r])
                res.WriteByte(' ')
            }
            r = l
        }
    }

    ans := res.String()

    return ans[:len(ans)-1]
}

// 示例 1：
// 输入：s = "the sky is blue"
// 输出："blue is sky the"


// 示例 2：
// 输入：s = "  hello world  "
// 输出："world hello"
// 解释：反转后的字符串中不能存在前导空格和尾随空格。


// 示例 3：
// 输入：s = "a good   example"
// 输出："example good a"
// 解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。