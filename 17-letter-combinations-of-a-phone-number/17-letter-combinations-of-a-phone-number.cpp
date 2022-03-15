class Solution {
public:
    
    unordered_map<char, string> map;
    vector<string> ans;
    
    void mapToChar() {
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
    }
    
    void backTrack(string digits, int i, string curStr) {
        if(curStr.size() == digits.size())
        {   
            ans.push_back(curStr);
            return;
        }
        for(auto c : map[digits[i]])
            backTrack(digits, i+1, curStr + c);
    }
    
    vector<string> letterCombinations(string digits) {

        mapToChar();
        if(digits.size())
            backTrack(digits, 0, "");
        return ans;
    }
};


/*
    Time: O(N * 4^N)
    
    2     3
    abc  def
    
    ad, ae, af
    bd, be, bf
    cd, ce, cf
    
    - Map the digits to the corrsponding characters
    - Backtrack
*/