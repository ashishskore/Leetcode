#include<iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int d, ListNode* n): data(d), next(n){}
};

ListNode* Reverse(ListNode* head, int K){

    ListNode* prev = nullptr, *next = nullptr;
    ListNode* cur = head;

    while(cur!=nullptr and K--){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

ListNode* ReverseAll(ListNode* head, int K){
    int count = 0;
    ListNode* prev = nullptr;
    ListNode* cur = head;
    ListNode* root = head;
    while(cur!= nullptr){
        root = cur;
        count = 0;

        // Iterate over List K Times Check if all K nodes present in the list
        // K - 2, 1 - 2 - 3  then it above cur will iterate 
        // through 1&2 and now it will point to 3
        while(cur!=nullptr and count < K){
            cur = cur->next;
            count++;
        }

        ListNode* frontnode = nullptr;
        if(count != K) {
            // not all K nodes left in the list so no need to rever
            frontnode = root;
        } else {
            frontnode = Reverse(root, K);
        }

        // Prev not present means First Reverse Happened
        if(prev == nullptr){
            head = frontnode;
        } else {
            prev->next = frontnode;
        }
        prev = root;
    }

    return head;
}

void PrintList(ListNode* ptr) {
    while(ptr != nullptr) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "\n";
}

int main(){
    ListNode* Head = new ListNode(1,nullptr);
    ListNode* ptr = Head;

    for (size_t i = 2; i <= 5; i++) {
        ptr->next = new ListNode(i, nullptr);
        ptr = ptr->next;
    }
    
    PrintList(Head);
    Head = ReverseAll(Head, 1);
    PrintList(Head);
}
