class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int cnt_zeroes = 0;
        for(int itr1 = 0, itr2 = 0; itr2 < nums.size(); itr2++)
        {
            if(nums[itr2] == 0)
                swap(nums[itr1], nums[itr2]), ++itr1, ++cnt_zeroes;
        }
        
        for(int itr1 = cnt_zeroes, itr2 = 0; itr2 < nums.size(); itr2++)
        {
            if(nums[itr2] == 1)
                swap(nums[itr1], nums[itr2]), ++itr1, ++cnt_zeroes;
        }
    }
};