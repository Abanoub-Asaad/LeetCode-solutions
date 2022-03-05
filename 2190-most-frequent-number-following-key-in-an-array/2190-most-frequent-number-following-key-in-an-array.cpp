class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] == key) um[nums[i+1]]++;
        }
        
        int mxTarget = INT_MIN, mxFreq = INT_MIN; 
        for(auto i = um.begin(); i != um.end(); i++) {
            if(i->second > mxFreq)
                mxFreq = i->second, mxTarget = i->first;
        }
        
        return mxTarget;
    }
};