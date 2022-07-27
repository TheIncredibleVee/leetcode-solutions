class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        vector<int> res({-1, -1});
        bool flag = false;
        while(low <= high){
            int mid = low + ((high-low) >> 1);
            if(nums[mid] == target) flag = true;
            if(nums[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        if(!flag){
            return res;
        }
        res[1] = high;
        low = 0;
        high = nums.size() - 1;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        res[0] = low;
        return res;
    }
};