class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size();
        string word = "", ans = "";
        
        for(int i = 0; i < n; i++) 
        {
            if(s[i] == ' ') 
            {
                continue;
            } 
            else if(i+1 == n || (i+1 != n && s[i+1] == ' ')) 
            {
                word+=s[i];
                if(ans.size()) 
                    ans = word + " " + ans;
                else 
                    ans = word;
                
                word = "";
            }
            else
            {
                word+=s[i];
            }
        }
        
        return ans;
    }
};


/*
    Make the sentence contain strings
    Add the strings into a vector of strings
    Reverse the vector
    Make the words in the vector as a sentence
    
    Time: O(N)
    Space: O(N)
    
    
    
    There's another solution without using a vector
    
    Time: O(N)
    Space: O(1)
*/