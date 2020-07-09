/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = NULL;
        ListNode* ret = NULL;
        int carry=0;
        bool flag = true;
        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            int digit = 0;
            if(flag)
            {
                ret = new ListNode();
                flag = false;
                answer = ret;
            }
            else
            {
                ret->next = new ListNode();
                ret = ret->next;
            }
            if(l1!=NULL)
                digit = l1->val;
            if(l2!=NULL)
                digit += l2->val;
            digit += carry;
            ret->val = digit % 10;
            carry = digit / 10;
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        return answer;
    }
};