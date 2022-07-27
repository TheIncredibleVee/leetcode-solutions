class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        multiset<int> s(nums1.begin(), nums1.begin() + m);
        s.insert(nums2.begin(), nums2.end());
        int i =0;
        for(auto &x: s){
            nums1[i++] = x;
        }
    }
};