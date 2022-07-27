class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> mp;
        if(s.length() < 2){
            return s.length();
        }
        mp[s[0]] = 0;
        int lastchar = 0;
        for(int i = 1; i < s.length(); ++i){
            if(mp.find(s[i]) != mp.end()){
                lastchar = max(lastchar, mp[s[i]] + 1);
            }
            res = max(res, i - lastchar + 1);
            mp[s[i]] = i;
        }
        return res;
    }
};