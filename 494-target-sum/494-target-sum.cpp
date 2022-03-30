class Solution {
public:
    
    // Time: O(N*T), T is the total number of targets that I can path
    // Space: O(N*T) 
    
    int dfs(vector<int>& nums, int target, int ind, unordered_map<string, int>&  dp) {
        if(ind == nums.size()) {
            return target == 0;
        }   
        
        string key = to_string(ind) + "_" + to_string(target);
        
        if(dp.count(key))
            return dp[key];
        
        int plus = dfs(nums, target - nums[ind], ind+1, dp);
        int minus = dfs(nums, target + nums[ind], ind+1, dp);
        
        return dp[key] = plus + minus;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        return dfs(nums, target, 0, dp);
    }
};

/*************************************
    Return the number of different expressions equals to target
    
    Brute force approach: 
      Time: O(2^N)
      Space: O(N), which is the heighest of the tree "recursive stack"
************************************
class Solution {
public:
    
    int dfs(vector<int>& nums, int target, int sum, int ind) {
        if(ind == nums.size()) 
            return sum == target;
      
        return dfs(nums, target, sum + nums[ind], ind+1) + 
               dfs(nums, target, sum - nums[ind], ind+1);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0, 0);
    }
};

*************************************/