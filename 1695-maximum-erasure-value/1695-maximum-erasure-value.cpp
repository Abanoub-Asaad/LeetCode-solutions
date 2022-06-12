/**************************************************
 Algorithm: Sliding Window and frequency array
   Time: O(N)
   Space: O(1)
****************************************************/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        bool freq[100005] = {false};
        int l = 0, n = nums.size();
        int mxScore = 0, prefixSum = 0;
        
        for(int r = 0; r < n; r++) {
            prefixSum += nums[r];
            if(freq[nums[r]]) {
                while(nums[l] != nums[r]) {
                    freq[nums[l]] = false;
                    prefixSum -= nums[l++];    
                }
                prefixSum -= nums[l++];
            } else {
                freq[nums[r]] = true;
            } 
            mxScore = max(mxScore, prefixSum);
        }
        
        return mxScore;
    }
};

/**************************************************
 Algorithm: Sliding Window and hash set
   Time: O(N)
   Space: O(N)
****************************************************
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> unique;
        int l = 0, n = nums.size();
        int mxScore = 0, prefixSum = 0;
        
        for(int r = 0; r < n; r++) {
            prefixSum += nums[r];
            if(unique.count(nums[r])) {
                while(nums[l] != nums[r]) {
                    unique.erase(nums[l]);
                    prefixSum -= nums[l++];    
                }
                prefixSum -= nums[l++];
            } else {
                unique.insert(nums[r]);
            } 
            mxScore = max(mxScore, prefixSum);
        }
        
        return mxScore;
    }
};
****************************************************/