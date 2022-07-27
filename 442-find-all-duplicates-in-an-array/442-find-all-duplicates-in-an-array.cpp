class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        res.reserve(n/2);
        unordered_set<int> st;
        for(int &num: nums){
            if(st.find(num) != st.end()){
                res.emplace_back(num);
            }
            st.insert(num);
        }
        return res;
    }
};