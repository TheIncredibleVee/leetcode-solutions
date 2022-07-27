class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> st;
        for(auto &x: nums){
            st.insert(x);
        }
        for(auto &num: nums){
            if(st.find(num - 1) == st.end()){
                if(st.find(num + res) == st.end()){
                    continue;
                }
                int temp = num + 1;
                while(st.find(temp) != st.end()){
                    temp++;
                }
                res = max(res, temp - num);
            }
        }
        return res;
    }
    
    /*
        Alternate Approach using sorting TC O(nlogn) but SC reduced to O(1)
    */
    
    // int longestConsecutive(vector<int>& nums) {
        // int n = nums.size();
        // if(n < 2){
        //     return n;
        // }
        // sort(nums.begin(), nums.end());
        // int curr = 1;
        // int res = 1;
        // for(int i = 1; i < n; ++i){
        //     if(nums[i] == nums[i - 1]){
        //         continue;
        //     }
        //     if(nums[i] == nums[i - 1] + 1){
        //         curr++;
        //     }else{
        //         res = max(res, curr);
        //         curr  = 1;
        //     }
        // }
        // return max(res, curr);
    // }
};