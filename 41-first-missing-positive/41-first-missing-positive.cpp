class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int cnt = 1;
        unordered_set<int> st;
        for(auto i : nums) {
            st.insert(i);
        }
        while(st.count(cnt)) {
            cnt++;
        } 
        return cnt;
    }
};

/*
    First Approach: O(n log n) time, O(1) space
        Sort the array
        Compare each element to the previous one 
        Print any missing positive num
            if there's no missing, print the valid num after the last element
    
    Second Approach: O(n) time, O(n) space 
        Initialize a hash set and insert all the elements into it
        Intialize a cnt variable to one
        Loop over cnt till it's not in the hash set
*/