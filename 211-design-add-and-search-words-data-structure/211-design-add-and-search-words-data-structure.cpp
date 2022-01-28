class WordDictionary {
public:
    
    unordered_map<int, vector<string>> wordsMap;
    
    WordDictionary() {}
    
    void addWord(string word) {
        wordsMap[word.size()].push_back(word);
    }
    
    bool search(string word) {
        
        if(!wordsMap.count(word.size()))
            return false;
        
        for(auto str : wordsMap[word.size()])
        {
            if(checkIfEqual(str, word))
                return true;
        }
        
        return false;
    }
    
    bool checkIfEqual(string str, string word) {
        
        bool isEqual = true;
        for(int i = 0; i < word.size(); i++)
        {
             if(word[i] != '.' && word[i] != str[i])
             {
                 isEqual = false;
                 break;
             }
        }
        return isEqual;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


/*
    MY THOUGHTS:
    
    1st Approach:- Using hash set
     Time Limit Exceeded (12/13 test)
     
        - Add words is done
        - Search for words
            - If the words doesn't contain any dots, it's done
            - Otherwise, brute force solution will be looping over the set and compare each 
                         word in the set to the dotted words.

        
    2nd Approach:- Using hash map
     The key is word's size, the value is the words

*/