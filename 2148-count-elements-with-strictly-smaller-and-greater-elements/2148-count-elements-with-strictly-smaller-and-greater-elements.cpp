class Solution {
public:
    int countElements(vector<int>& nums) {
        
        int n = nums.size(), ans = 0;
        
        if(n < 2)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int mn = nums[0], mx = nums[n-1];
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != mn && nums[i] != mx)
                ans++;
        }
        
        return ans;
    }
};