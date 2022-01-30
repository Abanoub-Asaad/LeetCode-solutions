class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     
        int sum = 0, res = 0;
        unordered_map<int, int> map;
        map[0]++;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(map[sum-k])
                res += map[sum-k];
            
            map[sum]++;
        }
        
        return res;
    }
};

/*
    [1,2,3], k = 3
    
    0 >> 1
    1 >> 1
    3 >> 1
    6 >> 1

*/