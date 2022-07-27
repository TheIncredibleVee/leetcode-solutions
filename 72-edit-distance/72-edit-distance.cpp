class Solution {
public:
    // int rec(string word1, string word2, int i, int j){
    //     if(i < 0){
    //         return j >= 0 ? j + 1: 0;
    //     }
    //     if(j < 0){
    //         return i >= 0 ? i + 1: 0; 
    //     }
    //     if(word1[i] == word2[j]){
    //         return rec(word1, word2, i - 1, j - 1);
    //     }
    //     return min(rec(word1, word2, i, j -1), min(rec(word1, word2, i - 1, j), rec(word1, word2, i - 1, j - 1)) ) + 1;
    // }
    int rec(string word1, string word2, int i, int j, vector<vector<int>> &dp){
        if(i == 0){
            return j;
        }
        if(j == 0){
            return i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(word1[i - 1] == word2[j - 1]){
            return dp[i][j] = rec(word1, word2, i - 1, j - 1, dp);
        }
        return dp[i][j] = min(rec(word1, word2, i, j -1, dp), min(rec(word1, word2, i - 1, j, dp), rec(word1, word2, i - 1, j - 1, dp)) ) + 1;
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        // for(int i = 0; i <= n; ++i){
        //     dp[i][0] = i;
        // }
        // for(int j = 0; j <= m; ++j){
        //     dp[0][j] = j;
        // }
        for(int i = 0; i <= m; ++i){
            prev[i] = i;
        }
        for(int i = 1; i <= n;++i){
            curr[0] = i;
            for(int j = 1; j <= m; ++j){
                if(word1[i - 1] == word2[j - 1]){
                    curr[j] = prev[j - 1];
                }else{
                    curr[j] = 1 + min(curr[j - 1], min(prev[j], prev[j - 1]));
                }
            }
            prev = curr;
        }
        return prev[m];
        // return rec(word1, word2, n, m, dp);
        // return rec(word1, word2, n - 1, m - 1);
    }
};