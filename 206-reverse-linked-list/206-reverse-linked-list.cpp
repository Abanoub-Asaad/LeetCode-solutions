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
    ListNode* reverseList(ListNode* head) {
        
        ListNode *nextNode, *prevNode = NULL;
  
        while(head) {
            nextNode = head -> next;
            head -> next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        
        return prevNode;
    }
};


/*
    head = 1, NULL
    prevNode = NULL
    nextNode = 2
        
       1 -> 2 -> 3 -> 4 -> 5
            ^
    Optimal Soluction:
     Time: O(N), Space: O(1)

    Brute force: 
     Time: O(N), Space: O(N)

*/