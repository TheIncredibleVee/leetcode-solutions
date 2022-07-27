class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int currPos = 1;
        int currNeg = 1;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            int temp = currPos;
            currPos = max(currPos*nums[i] , max(currNeg * nums[i], nums[i]));
            currNeg = min(currNeg*nums[i], min(temp * nums[i], nums[i]));
            res = max(res, currPos);
        }
        return res;
    }
};