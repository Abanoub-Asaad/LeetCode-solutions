class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char, int> lastIndex;
        vector<int> result;
        
        for(int i = 0; i < s.size(); i++)
            lastIndex[s[i]] = i;
        
        int subStrSize = 1, end = lastIndex[s[0]];
        
        for(int i = 1; i < s.size(); i++)
        {
            if(i > end) 
            {
                result.push_back(subStrSize);
                end = lastIndex[s[i]];
                subStrSize = 1;
            }
            else if(lastIndex[s[i]] > end)
                end = lastIndex[s[i]], ++subStrSize;
            else 
                ++subStrSize;    
        }
        
        result.push_back(subStrSize);
        return result;
    }
};


/*
    Time: O(n), 
    space: O(1) because it only stores english characters
    
    a b a b c b a c a d e  f  e  g  d  e  h  i  j  h  k  l  i  j
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23
                        ^
    size = 2, end = 15

    a: 8
    b: 5
    c: 7
    d: 14
    f: 11
    g: 13
    d: 14
    e: 15
    h: 19
    k: 20
    l: 21
    i: 22
    j: 23
    
    This video explains the idea in an amazing way:
    https://youtu.be/B7m8UmZE-vw
*/