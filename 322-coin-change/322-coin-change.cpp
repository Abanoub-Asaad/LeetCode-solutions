/*----------------------------------------------------------
    BFS Approach 
    2 important things:
    - Ignore when your diff goes below 0
    - Memoize using a visited set so that you don't re-calculate the branches of the graph   that you've already seen once
    
    Time: O(m^(n / c)) where m is the number of coins, n is the amount, and c is the smallest coin in the list of coins.
-------------------------------------------------------------*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(!amount)
            return 0;
        
        queue<int> q;
        unordered_set<int> visited;
        q.push(amount);
        visited.insert(amount);
        int minCoins = 0;
        
        while(q.size()) 
        {
            int n = q.size();
            minCoins++;
            while(n--) 
            {
                int cur = q.front();
                q.pop();
                for(int i = 0; i < coins.size(); i++) 
                {
                    if(cur-coins[i] == 0)
                        return minCoins;
                    if(cur-coins[i] > 0 && !visited.count(cur-coins[i]))
                        q.push(cur-coins[i]), visited.insert(cur-coins[i]);
                }
            }
        }
        
        return -1;
    }
};