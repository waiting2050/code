// 其实逻辑与单调栈法求lis是相似的，遍历数组中的每一个数num：
// 1．如果 num <= first，说明找到了一个更小的起点，更新first = num
// 2.否则，如果num <= second，说明num 适合做"二号位"，更新second = num 。
// 3．否则（即num 〉second），说明我们找到了一个比first 和second 都大的数，递增三元组成立！
// 很多人会有一个疑问：“如果first 被更新到了second 后面，顺序不就乱了吗？"
// 例子：[2，5，1，6]
// 1. 遇到 2：first = 2
// 2. 遇到 5：second = 5 (此时序列是 2, 5)
// 3. 遇到 1: first = 1 (此时 first=1， second=5)
// ·注意：虽然1在5后面，但second=5实际上隐含了“之前一定有一个比5小的数存在（即那个旧的2）"。
// 4。遇到6：6>second(5），返回true 。
// 有效序列其实是[2，5，6］，虽然此时 first 是1。
// 结论：second 的存在是依赖于"曾经有一个比它小的first 出现过"。所以只要能找到比second 大的数，三元组必然成立。
// 这里的逻辑和单调栈求lis是相似的

func increasingTriplet(nums []int) bool {
    mi, mid := math.MaxInt, math.MaxInt
    for _, val := range nums {
        if val <= mi {
            mi = val
        } else if val <= mid {
            mid = val
        } else {
            return true
        }
    }

    return false
}

// 示例 1：
// 输入：nums = [1,2,3,4,5]
// 输出：true
// 解释：任何 i < j < k 的三元组都满足题意


// 示例 2：
// 输入：nums = [5,4,3,2,1]
// 输出：false
// 解释：不存在满足题意的三元组


// 示例 3：
// 输入：nums = [2,1,5,0,4,6]
// 输出：true
// 解释：其中一个满足题意的三元组是 (1, 4, 5)，因为 nums[1] == 1 < nums[4] == 4 < nums[5] == 6