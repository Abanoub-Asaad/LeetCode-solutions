class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        unordered_map<int, int> freqMap;
        set<vector<int>> st;
        int n = nums.size();
        
        if(n < 3)
            return {};

        for(auto i : nums)
            freqMap[i]++;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++)
        {
            if(i && nums[i] == nums[i-1])
                continue;
                
            vector<int> onePair;
            for(int j = i+1; j < n; j++)
            {
                int thirdElement = -(nums[i]+nums[j]);
                freqMap[nums[i]]--, freqMap[nums[j]]--;
                
                if(freqMap.count(thirdElement) && freqMap[thirdElement] > 0)
                {
                    onePair = {nums[i], nums[j], thirdElement};
                    sort(onePair.begin(), onePair.end());
                    st.insert(onePair);
                }
                
                freqMap[nums[i]]++, freqMap[nums[j]]++; 
            }
        }
        
        for(auto i = st.begin(); i != st.end(); i++)
            result.push_back(*i);
        
        return result;
    }
};

/*
    1st Approach:- Time: o(n^3)
     It will give me time limit exceeded
    
     Input: nums = [-1,0,1,2,-1,-4]

      - Make 3 nested loops to get the pair of 3 that achive what I wanna do
      - Use set to get only the unique pairs
      
        If nums.size < 3
            return [];
            
    
     2nd Approach:- Time: O(n^2 log n)
     
      Input: nums = [-1,0,1,2,-1,-4]
      
      hash map <key, value>
       key = element, value = frequency
       -1 >> 2
        0 >> 1
        1 >> 1
        2 >> 1
       -4 >> 1
   

*/