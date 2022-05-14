//******* Second Approach

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int n = s.size();
        string curS = "";
        int cnt = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] != '#') {
                if(cnt)
                    cnt--;
                else 
                    curS += s[i];
            }
            else 
                cnt++;
        }
        
        n = t.size();
        string curT = "";
        cnt = 0;
        for(int i = n-1; i >= 0; i--) {
            if(t[i] != '#') {
                if(cnt)
                    cnt--;
                else 
                    curT += t[i];
            }
            else 
                cnt++;
        }
        
        return curS == curT;
    }
};

/*
    First Approach: using stacks
     Time: O(N), Space: O(N)
     
    Second Approach: iterating from the end to the start
     Time: O(N), Space: O(1)
*/

/*********************** First Approach
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

****************************************************/

