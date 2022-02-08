class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int count = 0, n = s.size();
        string result = "";
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                ++count;
            else if(s[i] == ')')
            {
                if(count)
                    --count;
                else 
                    s[i] = ' ';
            }
        }
        
        count = 0;
        
        for(int i = n-1; i >= 0; i--)
        {
             if(s[i] == ')')
                 ++count;
            else if(s[i] == '(')
            {
                if(count)
                    --count;
                else 
                    s[i] = ' ';
            }
        }
        
        for(auto i : s)
            if(i != ' ')
                result += i;
        
        return result;
    }
};