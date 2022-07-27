class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = INT_MIN;
        int n = nums.size();
        vector<int> presum;
        presum.reserve(n);
        int sum = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i){
            int x = nums[i];
            sum += x;
            presum.emplace_back(sum);
            res = max(res, x);
        }
        int lastSame = -1;
        for(int i = 0; i < n; ++i){
            if(mp.find(nums[i]) != mp.end()){
                lastSame = max(lastSame, mp[nums[i]]);
            }
            int nw = presum[i];
            // cout<<lastSame<<endl;
            if(lastSame != -1){
                nw -= presum[lastSame];
            }
            res = max(res, nw);
            mp[nums[i]] = i;
            
        }
        return res;
    }
};