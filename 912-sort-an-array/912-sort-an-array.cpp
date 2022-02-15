class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        vector<int> output;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i : nums)
            pq.push(i);
        while(pq.size()) {
            output.push_back(pq.top());
            pq.pop();
        }
        return output;
    }
};


/*
    I can use a priority queue to solve this problem
    
*/