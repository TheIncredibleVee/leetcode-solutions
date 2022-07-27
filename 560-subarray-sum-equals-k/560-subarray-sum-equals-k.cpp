class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        long long curr = 0;
        for(int i = 0; i < n; ++i){
            curr += nums[i];
            if(mp.find(curr - k) != mp.end()){
                res += mp[curr - k];
            }
            mp[curr]++;
        }
        return res;
    }
};