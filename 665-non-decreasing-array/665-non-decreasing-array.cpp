class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = false;
        int n = nums.size();
        for(int i = 0; i < n - 1; ++i){
            if(nums[i] > nums[i + 1]){
                if(flag){
                    return false;
                }
                flag = true;
                if(i != 0 && nums[i - 1] > nums[i + 1]){
                    nums[i + 1] = nums[i];
                }else{
                    nums[i] = nums[i + 1];   
                }
            }
        }
        return true;
    }
};