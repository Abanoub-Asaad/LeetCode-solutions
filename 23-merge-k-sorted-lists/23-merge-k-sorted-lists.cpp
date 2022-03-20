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

typedef pair<int, ListNode*> pi;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for(auto list : lists) {
            if(list)
                pq.emplace(make_pair(list->val, list));
        }
        
        auto head = new ListNode(-1);
        auto itr = head;
        while(pq.size()) 
        {
            auto cur = pq.top();
            itr->next = new ListNode(cur.first);
            itr = itr->next;
            pq.pop();
            if(cur.second -> next)
                pq.push({cur.second->next->val, cur.second->next});
        }
        
        return head->next;
    }
};

/*
    "Each linked-list is sorted in ascending order."

Brute force: O(N*M) time and space. N is the number of lists, M is the max list's size
    Loop over each linked list 
    Make a vector to have the values of all the linked list 
    Sort the vector
    Make a linked list and put the vector's elements into it

// With the brute force approach, i'm not taking an advantage of the sorted lists

    [[1,4,5],[1,3,4],[2,6]]
        ^       ^       ^
      
    Let's make a pointer over heads of each list 
    minHeap: [1, 1, 2]

    
Optimized approach: O(N*M) time, O(N) space. N is the number of lists, M is the max list's size
    
*/