class Solution {
    private:
        int rec(vector<int> &coins, int amount, vector<int> &dp){
            if(amount < 0 ){
                return -1;
            }
            if(amount == 0){
                return dp[0] = 0;
            }
            if(dp[amount] != -2){
                return dp[amount];
            }

            int res = INT_MAX;
            for(int i = 0; i< coins.size(); ++i){
                int subres = rec(coins, amount - coins[i], dp);
                if(subres != -1){
                    res = min(res, subres + 1);
                }
            }
            dp[amount] =  res == INT_MAX ? -1 : res;
            return dp[amount];
        }
public:
    
    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount + 1, -2);
        // return rec(coins, amount, dp);   
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= amount; ++i){
            for(int j = 0; j < coins.size(); ++j){
                if(coins[j] <= i && dp[i - coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1: dp[amount];
    }
};