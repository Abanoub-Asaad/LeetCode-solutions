class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
     
        if(finalSum & 1)
            return {};
        
        long long num = 2, c_sum = 0;
        vector<long long> ans;
        
        while(c_sum+num <= finalSum)
        {
            ans.push_back(num);
            c_sum += num;
            num += 2;
        }
        
        ans[ans.size()-1] += (finalSum-c_sum); 
        return ans;
    }
};



/*
    12
    [2,4,6]
         ^
     c_sum = 12
     num = 8
     finalSum = 12
    
    
    22
    [2,4,6,10]


*/