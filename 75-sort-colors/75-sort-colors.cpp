class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        for(int itr0 = 0, itr2 = n-1, i = 0; i <= itr2; )
        {
            if(nums[i] == 0)
                swap(nums[itr0], nums[i]), ++itr0, ++i;
            else if(nums[i] == 1)
                ++i;
            else if(nums[i] == 2)
                swap(nums[itr2], nums[i]), --itr2; 
        }
    }
};