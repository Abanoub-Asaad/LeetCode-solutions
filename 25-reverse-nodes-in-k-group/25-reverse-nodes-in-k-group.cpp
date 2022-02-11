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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        vector<int> primArr, finalArr;
        auto auxiliary_head = new ListNode(-1);
        auto itr = auxiliary_head;
        
        for(auto it = head; it; it = it -> next)
        {
            primArr.push_back(it->val);
            if(primArr.size() == k)
            {
                reverse(primArr.begin(), primArr.end());
                for(auto i : primArr)
                    finalArr.push_back(i);
                primArr.clear();
            }
        }
        
        if(primArr.size())
        {
            for(auto i : primArr)
                finalArr.push_back(i);
        }
        
        for(auto i : finalArr)
            cout << i << " ";
        
        for(int i = 0; i < finalArr.size(); i++, itr = itr -> next)
            itr -> next = new ListNode(finalArr[i]);
        
        return auxiliary_head -> next;
    }
};


/*

    k = 2
    [1,2,3,4,5]
    output: [2,1,4,3,5]
    
    k = 3
    [1,2,3,4,5]
    output: [3,2,1,4,5]
    
    Approach: 
      - Create an array of nodes
        Work on this array
        When I have a k nodes, I'll reverse them
      - Loop over the array
        
        
        primaryArr 1
         when the size of the primaryArr is = k, push the reversed into the finalArr
        finalArr 
*/