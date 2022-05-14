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
    a##c
    c
    
    ca#b##
    cnt = 2
    


*/