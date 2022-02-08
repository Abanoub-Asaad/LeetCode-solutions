class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> openBracketsIndices;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                openBracketsIndices.push(i);
            else if(s[i] == ')')
            {
                if(openBracketsIndices.empty())
                    s[i] = ' ';
                else 
                    openBracketsIndices.pop();
            }
        }
        
        string result = "";
        
        while(openBracketsIndices.size()) {
            s[openBracketsIndices.top()] = ' ';
            openBracketsIndices.pop();
        }
        
        for(auto i : s)
            if(i != ' ')
                result += i;
        
        return result;
    }
};