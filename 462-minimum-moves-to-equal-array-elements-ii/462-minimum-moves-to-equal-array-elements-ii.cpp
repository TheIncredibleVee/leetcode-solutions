class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res1 = 0;
        int res2 = 0;
        int option1 = nums[n/2];
        int option2 = nums[(n - 1)/2];
        for(auto &x: nums){
            res1 += abs(x - option1);
            res2 += abs(x - option2);
        }
        return min(res1, res2);
    }
};