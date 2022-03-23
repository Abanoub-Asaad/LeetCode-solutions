class Solution {
public:
    //--------------- Time: O(N)
    bool canJump(vector<int>& nums) {
        int goal = 1;
        int i = nums.size()-2; 
        if(nums.size() == 1)
            return true;
        while(i >= 0) 
        {
            if(nums[i] < goal)
                goal++;
            else 
                goal = 1;
            i--;
        }
        
        return (nums[0] >= goal) ? true : false;
    }
};


/*------------------------------------------
    Time: O(N^2)
--------------------------------------------
    class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, 0);
        visited[0] = 1;
        
        for(int i = 0; i < n; i++) 
        {
            for(int j = i+1; j <= i+min(nums[i], n-1); j++) {
                visited[j] = 1;
            }
            if(!visited[i])
                return false;
        }
            
        return visited[n-1];
    }
};
--------------------------------------------*/