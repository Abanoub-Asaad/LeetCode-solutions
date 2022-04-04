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
    ListNode* swapNodes(ListNode* head, int k) {
        auto helper = head;
        int n = 0;
        ListNode *startNode, *endNode;
        while(helper) {
            n++;
            if(n == k)
                startNode = helper;
            helper = helper->next;
        }
        
        int fromEnd = n - k, i = 0;
        helper = head;
        while(helper) {
            if(i == fromEnd)
                endNode = helper;
            i++, helper = helper->next;
        }
        
        swap(startNode->val, endNode->val);
        return head;
    }
};

/*
    n the length of the linked list
    swap kth and n - k 


    [1,2,3,4,5], k = 2, n = 0
       *   *
            ^ 
    start node
    end node
    swap(startNode->val, endNode->val)
    
    O(N)
    O(1)
*/