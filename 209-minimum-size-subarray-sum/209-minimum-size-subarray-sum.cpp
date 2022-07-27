class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int res = INT_MAX;
        int start = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            while(sum >= target){
                res = min(res, i - start + 1);
                sum -= nums[start++];
            }
        }
        return res == INT_MAX ? 0  : res;
    }
};