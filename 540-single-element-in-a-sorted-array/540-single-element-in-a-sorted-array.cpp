class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        int high = n-1;
        if(n==1){
            return nums[0];
        }
        if(nums[1]!= nums[0]){
            return nums[0];
        }
        if(nums[n-1] != nums[n-2]){
            return nums[n-1];
        }
        while(low <= high){
            cout<<high<<"\t"<<low<<"\n";
            int mid = (high + low)/2;
            if((mid > 0  && nums[mid-1] != nums[mid] ) && ( mid + 1 < n && nums[mid] != nums[mid + 1])){
                return nums[mid];
            }
            if(((mid % 2 == 0) && (nums[mid] == nums[mid-1])) || ((mid % 2 == 1) && (nums[mid] !=nums[mid - 1]))){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return nums[low];
    }
};