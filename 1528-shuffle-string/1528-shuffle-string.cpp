class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        unordered_map<int, char> mp;
        int n = indices.size();
        for(int i = 0; i < n; ++i){
            mp[indices[i]] = s[i];
        }
        string res = "";
        for(int i = 0; i < n; ++i){
            res += mp[i];
        }
        return res;
    }
};