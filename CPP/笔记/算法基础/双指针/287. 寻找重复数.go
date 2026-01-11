// 先将数组看成一个内向基环树，重复的数就是环的入口。如[1,3,4,2,2]，建立i->nums[i]的映射，即0->1, 1->3, 2->4, 3->2, 4->2。
// 可以发现，环的入口就是重复的数。之后的问题类似142. 环形链表 II。

func findDuplicate(nums []int) int {
    slow, fast := 0, 0
    for {
        slow = nums[slow]
        fast = nums[nums[fast]]
        if slow == fast {
            break
        }
    }

    head := 0
    for head != slow {
        head = nums[head]
        slow = nums[slow]
    }

    return head
}

// 示例 1：
// 输入：nums = [1,3,4,2,2]
// 输出：2


// 示例 2：
// 输入：nums = [3,1,3,4,2]
// 输出：3


// 示例 3 :
// 输入：nums = [3,3,3,3,3]
// 输出：3