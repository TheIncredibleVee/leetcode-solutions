class Solution {
public:
    // int rec(vector<int> &nums, int k, int idx, int n, vector<int> &dp){
    //     if( idx == n - 1){
    //         return nums[n - 1];
    //     }
    //     if(dp[idx] != -1){
    //         return dp[idx];
    //     }
    //     int res = nums[idx];
    //     int subRes = INT_MIN;
    //     for(int i = idx + 1; i <= min(n - 1, idx + k); ++i){
    //         subRes = max(subRes, rec(nums, k, i, n, dp));
    //     }
    //     res += subRes;
    //     return dp[idx] = res;
    // }
    int maxResult(vector<int>& nums, int k) {
        // int n = nums.size();
        // vector<int> dp(n + 1, -1);
        // dp[0] = nums[0];
        // for(int i = 1; i < n; ++i){
        //     dp[i] = nums[i];
        //     int subRes = INT_MIN;
        //     for(int j = i - 1; j >= 0 && j >=  i - k; j--){
        //         subRes = max(subRes, dp[j]);
        //     }
        //     dp[i] += subRes;
        // }
        // return dp[n - 1];
        // return rec(nums, k, 0, n, dp);
        deque<int> d{0};
        for (int i = 1; i < nums.size(); ++i) {
            if (d.front() + k < i)
                d.pop_front();        
            nums[i] += nums[d.front()];
            while (!d.empty() && nums[d.back()] <= nums[i])
                d.pop_back();
            d.push_back(i);
        }
        return nums.back();
    }
};