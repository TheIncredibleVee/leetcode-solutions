class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0]++;
        int presum = 0;
        for(int &val: nums){
            presum = (( presum + val )% k +k)%k;
            res += mp[presum]++;
        }
        return res;
    }
};