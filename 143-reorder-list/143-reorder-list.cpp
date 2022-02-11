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
    void reorderList(ListNode* head) {
     
        vector<ListNode*> arr;
        
        for(auto itr = head; itr ; itr = itr -> next)
            arr.push_back(itr);
        
        int L = 1, R = arr.size()-1;
        
        for(int i = 0; i < arr.size(); i++, head = head -> next)
        {
            if(i & 1)
                head -> next = arr[L++];
            else 
                head -> next = arr[R--];
        }
        
        head -> next = NULL;
    }
};
  

/*
    Time: O(N), Space: O(N)
    
    Use an additional space which is array to store the nodes
    
    Head is pointing to the first node in the list
    
    L = 1, which is the second node in the list
     bucase the first element which is head will not change in the result
    R = n - 1, to access the last node in the list 

*/