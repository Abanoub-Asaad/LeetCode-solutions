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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head -> next)
            return head;
        
        auto auxiliary_head = new ListNode(-1);
        auto iter = auxiliary_head;
        
        while(head) 
        {
            if(head -> next && head -> val == head -> next -> val)
            {
                int cur = head -> val;
                while(head && head -> val == cur) {
                    head = head -> next;
                }
            }
            else 
            {
                iter -> next = head;
                iter = iter -> next;
                head = head -> next;
            }
        }
        
        iter -> next = NULL; 
        return auxiliary_head -> next;
    }
};


/*
    Handle if the list is empty or it has only one element
    
    Loop then check 
        if the current node's value equals the next node's value, skip all the values
        Otherwise, add the value to the iterator
        
        

*/