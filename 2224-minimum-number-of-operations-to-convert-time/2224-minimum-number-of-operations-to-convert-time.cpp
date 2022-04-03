class Solution {
public:
    int convertTime(string current, string correct) {
        int required = 0, ans = 0;
        int minutesCurr =  stoi(current.substr(3,2));
        int hoursCurr = stoi(current.substr(0,2));
        int minutesCorr =  stoi(correct.substr(3,2));
        int hoursCorr = stoi(correct.substr(0,2));
        
        required +=  60 - minutesCurr + minutesCorr + ((hoursCorr - hoursCurr) - 1)*60;
        vector<int> operations = {60, 15, 5, 1};
        
        for(auto op : operations) {
            ans += required / op;
            required = required % op;
        }
        
        return ans;
    }
};