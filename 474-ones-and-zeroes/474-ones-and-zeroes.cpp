class Solution {
public:
    int rec(vector<pair<int,int>> &s, int m, int n, int pos, vector<vector<vector<int>>> &dp){
        if(pos == 0){
            return 0;
        }
        if(dp[m][n][pos] != -1){
            return dp[m][n][pos];
        }
        if(s[pos - 1].first > m || s[pos - 1].second > n){
            return dp[m][n][pos] = rec(s, m, n, pos - 1 ,dp);
        }
        return dp[m][n][pos] = max(1 + rec(s, m - s[pos - 1].first, n - s[pos - 1].second, pos - 1, dp), rec(s, m, n, pos - 1, dp));
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        // vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(strs.size() + 1 , -1)));
        vector<pair<int,int>> s;
        s.reserve(strs.size());
        for(auto x: strs){
            int one = 0;
            int zero = 0;
            for(auto c: x){
                if(c == '0'){
                    zero++;
                }else{
                    one++;
                }
            }
            s.emplace_back(zero, one);
        }
        int strsize = strs.size();
        vector<vector<int>> curr(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> prev(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i <= m; ++i){
            for(int j = 0; j <= n; ++j){
                prev[i][j] = 0;
            }
        }
        for(int pos = 1; pos <= strsize; ++pos){
            for(int i = 0; i <= m; i++){
                for(int j = 0; j <= n; ++j){
                    if(s[pos - 1].first > i || s[pos - 1].second > j){
                        curr[i][j] = prev[i][j];
                    }else{
                        curr[i][j] = max( 1 + prev[i - s[pos - 1].first][j - s[pos - 1].second], prev[i][j]);
                    }
                }
            }
            prev = curr;
        }
        return prev[m][n];
        // return dp[m][n][strsize];
        
        // return rec(s, m, n, (int)strs.size(), dp);
    }
};