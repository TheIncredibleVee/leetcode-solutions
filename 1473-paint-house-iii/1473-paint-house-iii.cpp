class Solution {
    private:
        int rec(vector<int> &houses, vector<vector<int>>& cost, int m, int n, int target, int idx, int nextColor, vector<vector<vector<int>>> &dp){
            if(idx == 0){
                if(target == 0){
                    return dp[target][idx][nextColor] = 0;
                }else{
                    return INT_MAX;
                }
            }
            if(target < 0){
                return INT_MAX;
            }
            if(dp[target][idx][nextColor] != -1){
                return dp[target][idx][nextColor];
            }
            if(houses[idx - 1] != 0 ){
                if(houses[idx - 1] != nextColor){
                    return dp[target][idx][nextColor] = rec(houses, cost, m, n, target - 1, idx - 1, houses[idx - 1], dp);
                }else{
                    return dp[target][idx][nextColor] = rec(houses, cost, m, n, target, idx - 1, houses[idx - 1], dp);
                }
            }
            int res = INT_MAX;
            for(int i = 0; i < n; ++i){
                int neighbour = (i + 1 != nextColor) ? 1 : 0;  
                int subRes = rec(houses, cost, m, n, target - neighbour, idx - 1, i + 1, dp);
                if(subRes != INT_MAX && res > subRes + cost[idx - 1][i]){
                    res = subRes + cost[idx - 1][i];
                }
            }
            return dp[target][idx][nextColor] = res;
        }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        int res = rec(houses, cost, m, n, target, m, 0, dp);
        return res==INT_MAX? -1 : res;
    }
};