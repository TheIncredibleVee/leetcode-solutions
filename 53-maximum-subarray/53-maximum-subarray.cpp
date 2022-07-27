class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> maxend(nums.size());
        maxend[0]=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();++i){
            maxend[i]=max(nums[i],nums[i]+maxend[i-1]);
            res=max(res,maxend[i]);
        }
        return res;
    }
};