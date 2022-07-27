class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int n = s.length();
        int prev = INT_MAX;
        for(int i = 0;i<n;++i){
            int cnt = 1;
            while(i+1<n && s[i] == s[i + 1]){
                cnt++;
                i++;
            }
            if(prev < mp[s[i]]){
                res -= 2*prev;
            }
            prev = cnt * mp[s[i]];
            res += prev;
        }
        return res;
    }
};