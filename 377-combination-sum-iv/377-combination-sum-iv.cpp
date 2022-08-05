class Solution {
private:
    long long rec(vector<int> &dp, vector<int>& arr, int n, int sum){
        if(sum == 0){
            return 1;
        }
        if(sum < 0){
            return 0;
        }
        if(dp[sum] != -1){
            return dp[sum];
        }
        long long res = 0;
        for(int i = 0; i < n; ++i){
            res += rec(dp, arr, n, sum - arr[i]);
        }
        return dp[sum] = res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, -1);
        return rec(dp, nums, n, target);
    }
};