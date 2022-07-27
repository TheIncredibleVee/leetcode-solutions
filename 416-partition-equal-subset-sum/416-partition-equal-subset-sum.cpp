class Solution {
    private:
    
        bool rec(vector<int> & nums, int index, int sum, vector<vector<int>> &dp){
            if(sum == 0){
                return true;
            }
            if(index == 0){
                return nums[0] == sum;
            }
            if(dp[index][sum] != -1){
                return dp[index][sum];
            }
            int take = nums[index] <= sum ? rec(nums, index - 1, sum - nums[index], dp): false;
            int noTake = rec(nums, index - 1, sum, dp);
            return dp[index][sum] = take + noTake;
        }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2){
           return false; 
        }
        sum = sum / 2;
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));
        // return rec(nums, (int)nums.size() - 1, sum, dp);  
        int n = nums.size();
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false));
        for(int i = 0; i < n; ++i){
            dp[i][0] = true;
        }
        for(int i = 1; i <= sum; ++i){
            dp[0][i] = nums[0] == i;
            for(int j = 1; j < n; ++j){
                bool take = nums[j] <= i ? dp[j - 1][i - nums[j]]: false;
                bool notake = dp[j - 1][i];
                dp[j][i] = take + notake;
            }
        }
        return dp[n - 1][sum];
            
    }
};