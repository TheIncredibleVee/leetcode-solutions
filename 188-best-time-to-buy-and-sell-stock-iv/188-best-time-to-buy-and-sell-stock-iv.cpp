class Solution {
private:
    int rec(vector<int>& arr, int i, int k, bool buy,vector<vector<vector<int>>> &dp){
        if(i == arr.size() || k <= 0){
            return 0;
        }
        if(dp[i][k][buy] != -1){
            return dp[i][k][buy];
        }
        if(buy){
            return dp[i][k][buy] = max(-arr[i] + rec(arr, i + 1, k, false, dp), rec(arr, i + 1, k, true, dp ));
        }else{
            return dp[i][k][buy] = max(arr[i] + rec(arr, i + 1, k - 1, true, dp), rec(arr, i + 1, k, false, dp));
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2,-1)));
        int res = rec(prices, 0, k, true, dp);
        return res;
    }
};