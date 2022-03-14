class Solution {
public:
    
    bool isValidFile(string s, int &numDots) {
        if(s.size() == 1 && s[0] == '.') {
            numDots = 1;
            return false;
        }
        if(s.size() == 2 && s[0] == '.' && s[1] == '.') {
            numDots = 2;
            return false;
        }
        return true;
    }
    
    string simplifyPath(string path) {
        
        string simplifiedPath = "";
        string file = "";
        vector<string> allFiles;
        stack<string> allValidFilesSt;
        
        // divide the path to words
        for(int i = 0; i < path.size(); i++) {
            if(path[i] != '/')
                file += path[i];
            else {
                if(file != "")
                    allFiles.push_back(file), file = "";
            }
        }
        
        if(file != "")
            allFiles.push_back(file);
        
        // work on pushing the valid words to the stack 
        for(auto word : allFiles) {
            int numDots = 0;
            bool match = isValidFile(word, numDots);
            if(match)
                allValidFilesSt.push(word);
            else {
                if(numDots == 2 && allValidFilesSt.size())
                    allValidFilesSt.pop();
            }
        }
        
        // reverse the order of the words in the stack using a helper stack
        stack<string> helper;
        while(allValidFilesSt.size()) {
            helper.push(allValidFilesSt.top());
            allValidFilesSt.pop();
        }
        
        // concatenate '/' before each word in a new string
        while(helper.size()) {
            simplifiedPath += "/" + helper.top();
            helper.pop();
        }
        
        return simplifiedPath == "" ? "/" : simplifiedPath;
    }
};