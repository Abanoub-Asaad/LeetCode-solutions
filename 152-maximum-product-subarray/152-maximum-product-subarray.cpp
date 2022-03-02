class Solution {
public:
    int maxProduct(vector<int>& nums) {
       
        int n = nums.size();
        int mx = INT_MIN, product = 1;
        
        for(auto i : nums) {
            mx = max(mx, product*=i);
            if(!i) product = 1;
        }
        
        product = 1;
        for(int i = n-1; i >= 0; i--) {
            mx = max(mx, product*=nums[i]);    
            if(!nums[i]) product = 1;
        }
        
        return mx;
    }
};


/*
    Get the largest product from a contiguous subarray
    
    Brute force: Get all the subarrays and compute the max product of them
        Time: O(N^2), Space: O(1)
    
    Optimized solution: Get the max from right to left, and then get the max from right to left
        Time: O(N), Space: O(1)
    

*/