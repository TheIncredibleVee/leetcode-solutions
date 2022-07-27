class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s==t;
        unordered_map<char, int> mp;
        for(auto x: s){
            mp[x]++;
        }
        for(auto x: t){
            mp[x]--;
        }
        for(auto x: mp){
            if(x.second != 0){
                return false;
            }
        }
        return true;
    }
};