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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     
        auto it1 = list1, it2 = list2;
        auto newHead = new ListNode(-1);
        auto dummyNode = newHead;
        
        while(it1 && it2) 
        {
            if (it1->val < it2->val)
            {
                newHead->next = new ListNode(it1->val);
                newHead = newHead->next;
                it1 = it1->next;
            } 
            else 
            {
                newHead->next = new ListNode(it2->val);
                newHead = newHead->next;
                it2 = it2->next;
            }
        }
        
        newHead -> next = (!it1) ? it2 : it1; 
        return dummyNode->next;
    }
};