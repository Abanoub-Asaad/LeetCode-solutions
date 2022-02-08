class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> openBrackets;
        vector<int> closeBrackets;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                openBrackets.push(i);
            else if(s[i] == ')')
            {
                if(openBrackets.empty())
                    closeBrackets.push_back(i);
                else 
                    openBrackets.pop();
            }
        }
        
        string result = "";
        
        while(openBrackets.size()) {
            s[openBrackets.top()] = ' ';
            openBrackets.pop();
        }
        
        for(auto i : closeBrackets)
            s[i] = ' ';
        
        for(auto i : s)
            if(i != ' ')
                result += i;
        
        return result;
    }
};

/*
    
   input: "lee(t(c)o)de)"
   )
   
   Input: s = "a)b(c)d"
        /
    
    Approach:
     - I will not care about the english letters 
     - I will use a stack for storing the brackets
        If the it's an open bracket, I will push to the stack
        Otherwise, 
            If the stack is not empty, I will pop the bracket from the stack
            Otherwise, I will increase the closeBrackets counter
            
        I can push the indices to the stack
        And also, instead of increasing the closeBrackets counter, 
                    I will push the indices into a vector
                    
        input: "lee(t(c)o)de)"
                stack: 
                12
    
*/