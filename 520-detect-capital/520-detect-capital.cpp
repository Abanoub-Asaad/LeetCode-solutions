class Solution {
public:
    bool detectCapitalUse(string word) {
        
        bool firstLetterIsCapital = false, secondLetterIsCapital = false, otherLettersAreCapitals = false;
        
        if(word.size() == 1)
            return true;
        
        for(int i = 0; i < word.size(); i++)
        {
            if(!i)
            {
                firstLetterIsCapital = (word[i] >= 'A' &&  word[i] <= 'Z');
            }
            else if(i == 1)
            {
                secondLetterIsCapital = (word[i] >= 'A' &&  word[i] <= 'Z');
            }
            else 
            {
                otherLettersAreCapitals = (word[i] >= 'A' &&  word[i] <= 'Z');
                
                if(otherLettersAreCapitals != secondLetterIsCapital)
                    return false;
            }
        }
        
        // All capitals, or all non capitals, or first is capital and the others are non capitals
        if(firstLetterIsCapital && secondLetterIsCapital)
            return true;
        if(!firstLetterIsCapital && !secondLetterIsCapital)
            return true;
        if(firstLetterIsCapital && !secondLetterIsCapital)
            return true;
        
        return false;
    }   
};

/*
    Loop over the whole string
        - if all letters capiltals, or all non capitals or only the first char is capital, return true
          else, return false
    
    How to check if it's capital?
        - compare the current char to A Z or a z
    
    
*/