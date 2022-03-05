class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        unordered_map<int, vector<int>> umap;
        vector<int> v;

        for(auto i : nums) 
        {
            int val = i, mappedVal = 0;
            int tens = 1;
            while(val) {
                int oneDigit = val%10;
                mappedVal += mapping[oneDigit]*tens, tens *= 10;
                val /= 10;
            }
            if(!i) 
                mappedVal = mapping[i];

            umap[mappedVal].push_back(i);
        }
        
        for(auto i = umap.begin(); i != umap.end(); i++) 
            v.push_back(i->first);
        
        sort(v.begin(), v.end());
        
        vector<int> ans;
        
        for(auto i : v) {
            for(auto j : umap[i])
                ans.push_back(j);
        }
        
        return ans;
    }
};
