class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i : stones)
            pq.push(i);
        while(pq.size() > 1) {
            int val1 = pq.top();
            pq.pop();
            int val2 = pq.top();
            pq.pop();
            
            int diff = abs(val1 - val2);
            if(diff) 
                pq.push(diff);
        }
        
        return (pq.size()) ? pq.top() : 0;
    }
};


/*
    Time O(NlogN)
    Space O(N)
*/