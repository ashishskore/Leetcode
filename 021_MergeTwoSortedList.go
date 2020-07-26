package main
import "fmt"

type ListNode struct{
	Val int
	Next *ListNode
}

func Create (nums []int)*ListNode {
	var head *ListNode = nil
	var ret *ListNode = nil
	for _,num := range nums {
		if head == nil{
			head = new(ListNode)
			ret = head
			ret.Val = num
			ret.Next = nil
		} else {
			ret.Next = &ListNode{
					Val : num,
					Next : nil,
				}
			ret = ret.Next
		}
	}
	return head
}

func Print(l *ListNode){
	for l!=nil {
		fmt.Print(l.Val,"->")
		l = l.Next
	}
	fmt.Println()
}

func Merge(l1 *ListNode, l2 *ListNode)*ListNode{
	var l *ListNode = nil
	var head *ListNode = nil
	if l1 == nil {
		return l2
	} 
	if l2 == nil {
		return l1
	}
	if l1.Val < l2.Val{
		head = l1
		l = head
		l1 = l1.Next
	} else {
		head = l2
		l = head
		l2 = l2.Next
	}
	for {
		if(l1==nil){
			l.Next = l2;
			return head
		}
		if(l2 == nil){
			l.Next = l1
			return head
		}
		if l1.Val < l2.Val{
			l.Next = l1
			l1 = l1.Next
		} else {
			l.Next = l2
			l2 = l2.Next
		}
		l = l.Next
	}
	return head
}

func main(){
	arr := []int {1,2,3,4}
	l1 := Create(arr)
	arr = []int {0,5,6,7,8}
	l2 := Create(arr)
	Print(l1)
	Print(l2)
	head := Merge(l1, l2)
	if head != nil{
		Print(head)
	}
}
