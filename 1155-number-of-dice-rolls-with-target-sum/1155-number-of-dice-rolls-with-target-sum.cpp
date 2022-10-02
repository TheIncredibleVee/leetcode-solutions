class Solution {
private:
    const int MOD = 1e9 + 7;
    int rec(int n, int k, int sum, vector<vector<long long>>& dp){
        if(n == 0 && sum == 0){
            return 1;
        }
        if(sum > n*k || sum < n || n <= 0){
            return 0;
        }
        if(dp[n][sum] != -1 ){
            return dp[n][sum];
        }
        long long res = 0;
        for(int i = 1; i <= k; ++i){
            if(sum - i >= 0){
                res %= MOD;
                res += (rec(n - 1, k, sum - i, dp) % MOD);    
            }
        }
        return dp[n][sum] = res;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, -1));
        return rec(n, k, target, dp) % MOD;
    }
};