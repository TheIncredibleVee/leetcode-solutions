class Solution {
public:
    int getMaxLen(vector<int>& nums){
        int n = nums.size(), maxLen = 0;
        int subArrayLen = 0, negCount = 0, firstNeg;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                subArrayLen = 0; negCount = 0;
            }
           else subArrayLen++;
           if(nums[i] < 0){
                if(negCount == 0) firstNeg = subArrayLen;
                negCount++;
            }
            if(negCount%2 !=0)maxLen = max(maxLen, subArrayLen - firstNeg);
            else maxLen = max(maxLen, subArrayLen);
        }
        return maxLen;
    }
};