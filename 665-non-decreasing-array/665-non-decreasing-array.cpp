/*****************************************************************
  Algorithm: Greedy
  Time: O(N)
  Space: O(1)
  
  Steps: 1. initiate 2 variables a counter and a minVal
         2. iterate over the array and 
            if the cur element <= the next, minVal = cur element
         3. otherwise, increase counter and 
           - if next < minVal, next = cur
           - otherwise, cur = next
*****************************************************************/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int minVal = INT_MIN;
        for(int i = 0; i < n-1; i++){
            if(nums[i] <= nums[i+1]){
                minVal = nums[i];
            } else {
                if(nums[i+1] < minVal) {
                    nums[i+1] = nums[i];
                } else {
                    nums[i] = nums[i+1];
                }
                cnt++;
            }
        }
        
        return cnt < 2;
    }
};

/****************************************************
  Algorithm: Brute force
  Time: O(N^2)
  Space: O(1)
  
  Steps: each time change one number and see if the 
         array becomes non decreasing or not.
******************************************************
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            bool flag = true;
            int changedNum = nums[i];
            nums[i] = (!i) ? INT_MIN : nums[i-1];
            for(int j = 1; j < n; j++) {
                if(nums[j] < nums[j-1]) {
                    flag = false;
                    break;
                }
            }
            nums[i] = changedNum;
            if(flag) {
                return true;
            }
        }
        
        return false;
    }
};
******************************************************/