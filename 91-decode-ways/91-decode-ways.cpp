class Solution {
private:
    int rec(string &s, int i, vector<int>& dp){
        if(i >= s.length()){
            return 1;
        }
        if(s[i] == '0'){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int res = rec(s, i + 1, dp);
        if(i + 1 < s.length() && (s[i] == '1' || (s[i] < '3' && s[i + 1] < '7'))){
            res += rec(s, i + 2, dp);
        }
        return dp[i] = res;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, -1);
        return rec(s, 0, dp);
    }
};