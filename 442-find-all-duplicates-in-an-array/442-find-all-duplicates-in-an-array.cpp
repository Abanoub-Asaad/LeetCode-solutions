class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> result;
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            int cur = abs(nums[i]);
            
            if(nums[cur-1] > 0)
                nums[cur-1] = -nums[cur-1];
            else 
                result.push_back(abs(nums[i]));
        }
        
        return result;
    }
};

/*

    1st Approach:- 
     Time: O(nlogn), Space: O(1)
     
     - sort the given array
     - compare elements to their next 
     
     
     2nd Approach: 
      Time: O(n), Space: O(n)
      
        - use a hash map 
        - store each element with its frequency 
        - loop through the hash map
            if i see element has frequency = 2, push it to the result array
     
     
     3rd Approach:- 
      Time: O(n), Space: O(1)
      
       nums = [4,3,2,7,8,2,3,1]
                             ^
       nums after negation: [-4,-3,-2,-7,8,2,-3,-1]
        
       output: [3,2]
       
            - loop through the given array 
              curr = abs(arr[i])
              if nums "after negation" has a neg value, push abs of this element to the result
              otherwise, get the negative value of nums[cur-1]
              
              [10,2,5,10,9,1,1,4,3,7]
                                ^
          
        
*/