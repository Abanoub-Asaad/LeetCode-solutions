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
    ListNode* swapPairs(ListNode* head) {
        
        auto auxiliary_head = new ListNode(-1);
        auto iter = auxiliary_head;
        
        while(head) 
        {
            if(head -> next) 
            {
                auto *firstNode = new ListNode(head -> val);
                auto *secondNode = new ListNode(head -> next -> val);
                iter -> next = secondNode;
                iter -> next -> next = firstNode;
                iter = iter -> next -> next;
                head = head -> next;
            } 
            else
            {
                iter -> next = head;
            }
            head = head -> next;
        }
        
        return auxiliary_head -> next;
    }
};