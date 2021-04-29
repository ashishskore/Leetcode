/**

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class ListNode;
class comp{
	public :
    bool operator()(const ListNode* a, const ListNode* b){
		return a->val > b->val;
	}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> p;
        
	    for(ListNode* list : lists) {
	    	if(list != nullptr)
		    	p.push(list);
	    }
	
    	ListNode* head = nullptr, *curr = nullptr;
        if (not p.empty())
        {
            head = curr = p.top();
            p.pop(); 
            
            if(curr->next != nullptr)
	    	    p.push(curr->next);
        }
    	
    	ListNode* ptr = nullptr;
        
	    while(not p.empty()) {
	    	ptr = p.top();
	    	p.pop();
	    	curr->next = ptr;
	    	curr = curr->next;
		
	    	if(ptr->next != nullptr)
		    	p.push(ptr->next);
	    }
        return head;
    }
};
