// 双指针，rd负责读，wt负责写，st负责辅助记录新的起始位置

func compress(chars []byte) int {
    n, wt, st := len(chars), 0, 0
    for rd := 0; rd < n; st = rd {
        for rd < n && chars[rd] == chars[st] {
            rd++
        }

        chars[wt] = chars[st]
        wt++

        cnt := rd - st
        if cnt > 1 {
            s := strconv.Itoa(cnt)
            for i := 0; i < len(s); i++ {
                chars[wt] = s[i]
                wt++
            }
        }
    }

    return wt
}

// 示例 1：
// 输入：chars = ["a","a","b","b","c","c","c"]
// 输出：返回 6 ，输入数组的前 6 个字符应该是：["a","2","b","2","c","3"]
// 解释："aa" 被 "a2" 替代。"bb" 被 "b2" 替代。"ccc" 被 "c3" 替代。


// 示例 2：
// 输入：chars = ["a"]
// 输出：返回 1 ，输入数组的前 1 个字符应该是：["a"]
// 解释：唯一的组是“a”，它保持未压缩，因为它是一个字符。


// 示例 3：
// 输入：chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
// 输出：返回 4 ，输入数组的前 4 个字符应该是：["a","b","1","2"]。
// 解释：由于字符 "a" 不重复，所以不会被压缩。"bbbbbbbbbbbb" 被 “b12” 替代。