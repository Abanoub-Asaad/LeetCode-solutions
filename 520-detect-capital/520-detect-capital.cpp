class Solution {
public:
    bool detectCapitalUse(string word) {
        
        bool currentLetterIsCapital = false;
        
        if(word.size() == 1)
            return true;
        
        bool firstLetterIsCapital = isupper(word[0]);
        bool secondLetterIsCapital = isupper(word[1]);
            
        for(int i = 2; i < word.size(); i++)
        {
            currentLetterIsCapital = (word[i] >= 'A' && word[i] <= 'Z');
                
            if(currentLetterIsCapital != secondLetterIsCapital)
                return false;
        }
        
        if(firstLetterIsCapital && secondLetterIsCapital)
            return true;
        if(!firstLetterIsCapital && !secondLetterIsCapital)
            return true;
        if(firstLetterIsCapital && !secondLetterIsCapital)
            return true;
        
        return false;
    }   
};