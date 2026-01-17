// 容易想到遍历奇、偶数下标的节点，然后将他们分别串联，最后将偶数头接在奇数尾后面即可。但是重连节点的时候会破坏链表原有的结构，
// 于是要利用指针节点而不是原有的结构去获取节点，比如odd连谁，由even去找；反之even由odd去找。

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
    if head == nil {
        return nil 
    }

    rem, odd, even := head.Next, head, head.Next
    for even != nil && even.Next != nil {
        odd.Next = even.Next
        odd = odd.Next
        even.Next = odd.Next
        even = even.Next
    }
    odd.Next = rem

    return head
}

// 示例 1:
// 输入: head = [1,2,3,4,5]
// 输出: [1,3,5,2,4]


// 示例 2:
// 输入: head = [2,1,3,5,6,4,7]
// 输出: [2,3,6,7,1,5,4]