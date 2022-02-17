class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int>mp;
        
        for (int i=0; i<nums.size(); i++)
        {
            int numberToBeFound = target - nums[i];
            if (mp.count(numberToBeFound)) 
                return {mp[numberToBeFound], i};
                
            mp[nums[i]]=i; 
        }
        
        return {};
    }
};