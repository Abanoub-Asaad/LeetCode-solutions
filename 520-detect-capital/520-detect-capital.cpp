class Solution {
public:
    bool detectCapitalUse(string word) {
        
        bool currentLetterIsCapital = false;
        
        if(word.size() == 1)
            return true;
        
        bool firstLetterIsCapital = (word[0] >= 'A' && word[0] <= 'Z');
        bool secondLetterIsCapital = (word[1] >= 'A' && word[1] <= 'Z');
            
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