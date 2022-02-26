class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++) 
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        
        return dp[n-1];
    }
};

/*
    - Get Max amount of money without alerting the police
    - Can i skip more than one house? YES
    - Think of dividing the probem to subprobems
    
        [1] -> 1
        [1,9] -> 9
        [1,9,10] -> 11
        [1,9,10,15] -> 25, max(prev, prev-lastElemPrev+lastElemNow) 
        
        
    - Brute force solution to this probem is to get all valid 
        combinations and then loop over them to get the max amount 
        of money

*/