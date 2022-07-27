class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, 1);
        // int res = 1;
        // for(int i = n - 1; i >= 0; --i){
        //     for(int j = n - 1; j > i; --j){
        //         if(nums[i] < nums[j]){
        //             dp[i] = max(dp[i], 1 + dp[j]);
        //         }
        //     }
        //     res = max(res, dp[i]);
        // }
        vector<int> subres;
        subres.reserve(n);
        for(int i = 0; i < n; ++i){
            if(subres.empty() || nums[i] > subres.back()){
                subres.emplace_back(nums[i]);
            }else{
                *lower_bound(subres.begin(), subres.end(), nums[i]) = nums[i];
            }
        }
        return subres.size();
    }
};