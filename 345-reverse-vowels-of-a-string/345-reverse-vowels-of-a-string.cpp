class Solution {
public:
    string reverseVowels(string s) {
        
        int i = 0;
        int j = s.size()-1;
        unordered_set<char> vowelsSet = {'a', 'e', 'i', 'o', 'u'};
        
        while(i<j)
        {
            bool flag1 = false, flag2 = false;   // to check if we are pointing to a vowel or not
            
            if(vowelsSet.count(tolower(s[i])))
                flag1 = true;
            
            if(vowelsSet.count(tolower(s[j])))
                flag2 = true;
            
            if(flag1 && flag2)   // if both are pointing to vowels just swap them
            {
                swap(s[i],s[j]);
                i++;j--; 
            }
            
            if(!flag1) i++;
            if(!flag2) j--;
        }
        
        return s;
    }
};