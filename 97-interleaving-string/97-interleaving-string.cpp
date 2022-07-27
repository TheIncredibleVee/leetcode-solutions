class Solution {
    private:
        bool rec(string &s1, string &s2, string &s3, int a, int b, int c, vector<vector<vector<int>>> &dp){
            if(dp[a][b][c] != -1){
                return dp[a][b][c];
            }
            if(c == 0 && a == 0 && b == 0){
                return dp[a][b][c] = true;
            }
            if(a == 0 ){
                return dp[a][b][c] = s2.substr(0, b) == s3.substr(0, c);
            }
            if(b == 0){
                return dp[a][b][c] = s1.substr(0, a) == s3.substr(0, c);
            }
            bool res = false;
            if(s3[c - 1] == s1[a - 1]){
                res = res || rec(s1, s2, s3, a - 1, b, c - 1, dp);
            }
            if(res){
                return dp[a][b][c] = true;
            }
            if(s3[c - 1] == s2[b - 1]){
                res = res || rec(s1, s2, s3, a, b - 1, c - 1, dp);
            }
            return dp[a][b][c] = res;
        }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.length();
        int b = s2.length();
        int c = s3.length();
        if(a + b != c){
            return false;
        }
        vector<vector<vector<int>>> dp(a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1, -1)));
        return rec(s1, s2, s3, a, b, c, dp);
    }
};