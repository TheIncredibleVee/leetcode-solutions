class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nxtGreater(nums2.size(), -1);
        unordered_map<int, int> mp;
        for(int i = 0; i < nums2.size(); ++i){
            mp[nums2[i]] = i;
        }
        int n = nums2.size();
        stack<int> s;
        s.push(n-1);
        for(int i = n-2; i>=0;--i){
            while(!s.empty() && nums2[s.top()] <= nums2[i]){
                s.pop();
            }
            if(!s.empty()){
                nxtGreater[i] = nums2[s.top()];
                // cout<<i<<"\t"<<s.top()<<endl;
            }
            s.push(i);
        }
        vector<int> res;
        for(auto x : nums1){
            res.push_back(nxtGreater[mp[x]]);
        }
        return res;
    }
};