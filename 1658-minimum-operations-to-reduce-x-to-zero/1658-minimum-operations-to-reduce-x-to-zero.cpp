/********************************************************************
  Time: O(N)
  Space: O(1)
*********************************************************************
  Algorithm: using sliding window and prefix sum
    - Get the totalSum of the array
    - subtract x from the totalSum, (toFind = totalSum - x)
    - Instead of finding min nums which their sum equal to x,
      we can find max num of elements in subarray, their sum = toFind  
**********************************************************************/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int toFind = totalSum - x;
        int n = nums.size(), l = 0;
        int prefixSum = 0, mx = -1;
        
        if(totalSum < x)
            return -1;
        if(totalSum == x)
            return n;
            
        for(int r = 0; r < n; r++) {
            prefixSum += nums[r];
            if(prefixSum > toFind) {
                while(prefixSum > toFind) {
                    prefixSum -= nums[l++];
                }
            } 
            if(prefixSum == toFind) {
                mx = max(mx, r-l+1);            
                prefixSum -= nums[l++];
            }
        }
        
        return (mx == -1) ? mx : n-mx;
    }
};