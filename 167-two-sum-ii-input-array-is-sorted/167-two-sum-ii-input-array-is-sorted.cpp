/********************************************************************
 Optimized Solution:- Use two pointers 
  Time: O(N)
  Space: O(1)
*********************************************************************/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r) {
            if(nums[l] + nums[r] == target)
                return {l+1, r+1};
            else if(nums[l] + nums[r] > target)
                r--;
            else 
                l++;
        }
        
        return {};
    }
};

/********************************************************************
 Another Solution:- make a hash map to store the num and its index
  Time: O(N)
  Space: O(N)
*********************************************************************
    class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        int n = numbers.size();
        for(int i = 0; i < n; i++) {
            int toFind = target-numbers[i];
            if(mp.count(toFind))
                return {mp[toFind]+1, i+1};
            else 
                mp[numbers[i]] = i;
        }
        
        return {};
    }
};
*********************************************************************


/********************************************************************
 Another Solution:- Do binary search to find the target number
  Time: O(N log N)
  Space: O(1)
*********************************************************************
class Solution {
public:
    
    struct Num {
        bool found = false;
        int ind;
    };
    
    Num search(vector<int>& nums, int toFind, int low, int high) {
        Num num_struct;
        int mid;    
        while(low <= high) {
            mid = (low + high)/2;
            if(nums[mid] == toFind) {
                num_struct.found = true;
                num_struct.ind = mid;
                return num_struct;
            } else if(nums[mid] < toFind) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }    
        }
        
        return {};
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0; i < n-1; i++) {
            int toFind = target - numbers[i];
            Num num = search(numbers, toFind, i+1, n-1);
            if(num.found)
                return {i+1, num.ind+1};
        }
        
        return {};
    }
};
*********************************************************************/