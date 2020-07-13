/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 * 1 -> 2 -> 3 -> 4
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    start := &ListNode{Next:head}
    front := start
    back := start
    for i:=0; i<n+1; i++ {
        front = front.Next
    }
    for front != nil{
        front = front.Next
        back = back.Next
    }
    back.Next = back.Next.Next
    return start.Next
}
