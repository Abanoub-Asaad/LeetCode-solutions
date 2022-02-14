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
        
        if(!it1 && !it2)
            return {};
        
        while(it1 || it2) 
        {
            if(!it1)
            {
                newHead->next = new ListNode(it2->val);
                newHead = newHead->next;
                it2 = it2->next;
            }
            else if(!it2)
            {
                newHead->next = new ListNode(it1->val);
                newHead = newHead->next;
                it1 = it1->next;
            }
            else if (it1->val < it2->val)
            {
                newHead->next = new ListNode(it1->val);
                newHead = newHead->next;
                it1 = it1->next;
            } 
            else if(it1->val > it2->val)
            {
                newHead->next = new ListNode(it2->val);
                newHead = newHead->next;
                it2 = it2->next;
            }
            else 
            {
                newHead->next = new ListNode(it1->val);
                newHead->next->next = new ListNode(it1->val); 
                newHead = newHead->next->next;
                it1 = it1->next, it2 = it2->next;
            }
        }
        
        return dummyNode->next;
    }
};