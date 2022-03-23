class Solution {
public:
    
    unordered_set<string> uniCombinations;
    
    string solve(vector<int> currComb) {
        sort(currComb.begin(), currComb.end());
        string key;
        for(auto i : currComb) {
            key += to_string(i) + ",";
        }
        return key;
    }
    
    void dfs(vector<int>& candidates, int target, int currSum, vector<int>& currComb, vector<vector<int>> &ans) {
        if(currSum > target) //backtrack
            return; 
        if(currSum == target) //store the solution and backtrack
        { 
            string key = solve(currComb);
            if(!uniCombinations.count(key))
                ans.push_back(currComb), uniCombinations.insert(key);
            return;
        }
        
        for(auto i : candidates) { //try all possible options for the next level
            if(currSum + i > target)
                break;
            currSum += i;
            currComb.push_back(i); //put one option into the combination
            dfs(candidates, target, currSum, currComb, ans); //try with this combination, whether it gives a solution or not.
            currSum -= i;
            currComb.pop_back(); //when this option backtrack to here, remove this and go on to the next option.
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> currComb;
        dfs(candidates, target, 0, currComb, ans);
        return ans;
    }
};