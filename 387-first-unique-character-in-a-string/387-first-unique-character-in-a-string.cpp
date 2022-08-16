class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hash(26);
        int res = INT_MAX;
        int idx = 0;
        unordered_map<char,int> mp;
        for(char &c:s){
            hash[c - 'a']++;
            mp[c] = idx++;
        }
        for(int i = 0; i < 26; ++i){
            if(hash[i] == 1){
                res = min(res, mp['a' + i]);
            }
        }
        return res == INT_MAX ? -1: res;
    }
};