class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        res.reserve(queries.size());
        int curr = 0;
        for(int &x: nums){
            if(x%2 == 0){
                curr += x;
            }
        }
        for(vector<int>& query: queries){
            int pos = query[1];
            int val = query[0];
            if(nums[pos] % 2){
                if(val % 2){
                    curr += nums[pos] + val;
                }
            }else{
                if(val%2){
                    curr -= nums[pos];
                }else{
                    curr += val;
                }
            }
            nums[pos] += val;
            res.emplace_back(curr);
        }
        return res;
    }
};