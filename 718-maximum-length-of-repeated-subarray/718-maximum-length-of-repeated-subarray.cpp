class Solution {
public:
    // int findLength(vector<int>& nums1, vector<int>& nums2) {
    //     int res = 0;
    //     int n = nums1.size();
    //     int m = nums2.size();
    //     if(n < m){
    //         return findLength(nums2, nums1);
    //     }
    //     unordered_map<int, vector<int>> mp;
    //     for(int i = 0;i < m; ++i){
    //         mp[nums2[i]].push_back(i);
    //     }
    //     for(int i = 0; i < n; i++){
    //         int elem = nums1[i];
    //         // cout<<elem<<" "<<mp[elem].size()<<endl;
    //         for(int j = 0; j < mp[elem].size(); j++){
    //             int curr = 1;
    //             int pos1 = i + 1;
    //             int pos2 = mp[elem][j] + 1;
    //             while(pos1 < n && pos2 < m && nums1[pos1] == nums2[pos2]) pos1++, pos2++, curr++;
    //             res = max(res, curr);
    //         }    
    //     }
    //     return res;
    // }
    int rec(vector<int>& a, vector<int>& b, int idx1, int idx2, int n, int m, vector<vector<int>>& dp, int& res){
        if(idx1 >= n || idx2 >= m){
            return 0;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        rec(a,b, idx1 + 1, idx2 , n, m,dp, res);
        rec(a,b, idx1, idx2 + 1, n, m, dp, res);
        dp[idx1][idx2] = 0;
        if(a[idx1] == b[idx2]){
            dp[idx1][idx2] = max(dp[idx1][idx2], 1 + rec(a,b,idx1 + 1, idx2 + 1, n, m, dp,res));
        }
        res = max(res, dp[idx1][idx2]);
        return dp[idx1][idx2];
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        rec(nums1, nums2, 0, 0, n, m, dp, res);
        return res;
    }
};