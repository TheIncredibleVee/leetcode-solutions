class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
//         int res = INT_MAX;
//         int n = nums.size();
//         long long sum = 0;
//         vector<int> presum;
//         presum.reserve(n);
//         long long curr = 0;
//         for(int i = 0; i < n; ++i){
//             sum += nums[i];
//             if(sum == x){
//                 res = i + 1;
//             }
//         }
//         if(x > sum){
//             return -1;
//         }
//         if( x == sum){
//             return n;
//         }
//         long long reqSum = sum - x;
//         int left = 0;
//         int right = 0;
//         curr = 0;
//         while(right < n && left <= right){
//             if(curr < reqSum){
//                 curr += nums[right++];
//             }else{
//                 if(curr == reqSum){
//                     res = min(res, n - ( right - left));
//                     curr += nums[right++];
//                 }else{
//                     while(curr > reqSum && left < right){
//                         curr -= nums[left++];
//                     }
//                 }
//             }
            
//         }
//         return res == INT_MAX ? -1 : res;
        // int sum = accumulate(begin(nums), end(nums), 0);
        // int l = 0, r = 0, res = INT_MAX, sz = nums.size();
        // while (l <= r)
        //     if (sum >= x) {
        //         if (sum == x)
        //             res = min(res, l + sz - r);
        //         if (r < sz)
        //             sum -= nums[r++];
        //         else
        //             break;
        //     }
        //     else
        //         sum += nums[l++];
        // return res == INT_MAX ? -1 : res;
        unordered_map<int, int> left;
        
        left.emplace(0, -1);
        for (int l = 0, sum = 0; l < nums.size() && sum + nums[l] <= x; ++l)
            left.emplace(sum += nums[l], l);
        
        int res = INT_MAX;
        for (int r = nums.size()-1, sum = 0; r >= 0 && sum <= x; --r) {
            auto it = left.find(x-sum);
            if (it != end(left) && r >= it->second)
                res = min(res, (int)nums.size() - r + it->second);
            sum += nums[r];
        }
        return res == INT_MAX ? -1 : res;
    }
};