// Fine-Wilf 定理,被誉为“字符串研究中的最大公约数定理”。
// 简单来说，它规定了：当一个字符串同时拥有两个周期时，在什么条件下它必然会拥有一个更小的周期（即这两个周期的最大公约数）。
// 假设一个字符串S具有两个周期p和q。如果S的长度n满足：n ≥ p + q - gcd(p,q)，那么，GCD(p,q)也是 S的一个周期。
// 对于这道题来讲，p就是str1，q就是str2，n就是str1+str2，那么定理肯定成立。
// 如果str1和str2的最大公因子存在，那么它必然是str1和str2的公共前缀。
// 或者常规做法就是枚举因子，然后判断是否是公共前缀。

func gcdOfStrings(str1 string, str2 string) string {
    if str1 + str2 != str2 + str1 {
        return ""
    }

    return str1[:gcd(len(str1), len(str2))]
}

func gcd(a, b int) int {
    if b == 0 {
        return a
    } else {
        return gcd(b, a % b)
    }
}

// 示例 1：
// 输入：str1 = "ABCABC", str2 = "ABC"
// 输出："ABC"


// 示例 2：
// 输入：str1 = "ABABAB", str2 = "ABAB"
// 输出："AB"


// 示例 3：
// 输入：str1 = "LEET", str2 = "CODE"
// 输出：""


// 示例 4：
// 输入：str1 = "AAAAAB", str2 = "AAA"
// 输出：""