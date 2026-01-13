// 1、根据空格切割单词，但是空格有多个，strings.Fields刚好可以去掉单/多个空格以及首尾空格，提取出单词
// 2、遍历前半部分数组，直接和后半部分的对应位置交换
// 3、数组重组成字符串
// strings.Fields可以将空白符看作分割标识，将字符串变成拆成字符串数组，复杂度都是O(n)；strings.Join可以将字符串数组拼接成
// 一个字符串，复杂度O(n)，因为实际使用byte[]来操作，在返回时直接用unsafe转成string(复杂度O(1))，所以非常快。

func reverseWords(s string) string {
    t := strings.Fields(s)
    n := len(t)
    for i := 0; i < n / 2; i++ {
        t[i], t[n - 1 - i] = t[n - 1 - i], t[i]
    }
    ans := strings.Join(t, " ")

    return ans
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