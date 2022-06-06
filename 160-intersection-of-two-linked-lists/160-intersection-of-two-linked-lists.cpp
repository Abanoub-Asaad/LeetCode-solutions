/******************************************************
    Optimized Solution: TC(N), SC(1)
        - Know the len of each linked list
        - Compare each linked list's head to the other
 *******************************************************/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *dummyA = headA, *dummyB = headB;
        while(dummyA) {
            lenA++;
            dummyA = dummyA->next;
        } 
        while(dummyB) {
            lenB++;
            dummyB = dummyB->next;
        } 
        
        int n = max(lenA, lenB);   
        while(n--) {
            if(headA == headB)
                return headA;
            if(lenA > lenB)
                headA = headA->next, lenA--;
            else if(lenB > lenA)
                headB = headB->next, lenB--;
            else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        
        return nullptr;
    }
};

/********************************************************************************
    One Solution: TC(N), SC(N) 
     - Make a hash set and insert all the nodes of headA into it
     - Iterate over the second linked list "headB", and check if the cur node in 
       the hash set
********************************************************************************
    class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> nodes;
        while(headA) {
            nodes.insert(headA);
            headA = headA->next; 
        }
        while(headB) {
            if(nodes.count(headB))
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};
*********************************************************************************/