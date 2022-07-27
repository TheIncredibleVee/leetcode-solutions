class Solution {
    private:
        int rec(vector<int>& arr, int n, int idx, bool prev, vector<vector<int>> &dp){
            if(idx == 0){
                return 0;
            }
            if(prev && (idx == 1 || idx == 2)){
                return min(arr[0], arr[1]);
            }
            if(idx == 1 || idx == 2){
                return arr[idx - 1];
            }
            if(dp[idx][prev] != -1){
                return dp[idx][prev];
            }
            int res = arr[idx - 1] + rec(arr, n, idx - 1, true, dp);
            if(prev){
                res = min(res, rec(arr, n, idx - 1, false, dp));
            }
            return dp[idx][prev] = res;
        }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return rec(cost,n, n, true, dp);
    }
};