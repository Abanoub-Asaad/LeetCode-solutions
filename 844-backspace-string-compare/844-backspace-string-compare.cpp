class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> stackS, stackT;
        for(auto i : s) {
            if(i != '#')
                stackS.push(i);
            else if(stackS.size())
                stackS.pop();
        }
        for(auto i : t) {
            if(i != '#')
                stackT.push(i);
            else if(stackT.size())
                stackT.pop();
        }
        
        //compare the two stacks
        while(stackS.size() && stackT.size()) {
            if(stackS.top() == stackT.top()) 
                stackS.pop(), stackT.pop();
            else 
                return false;
        }
        return (stackS.empty() && stackT.empty()) ? true : false;
    }
};

/*
    First Approach: using stacks
     Time: O(N), Space: O(N)
     
    Second Approach: 

*/

