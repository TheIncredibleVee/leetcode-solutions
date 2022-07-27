class Solution {
public:
    int rec(string word1, string word2, int i, int j, vector<vector<int>> &dp){
        if(i == 0){
            return j > 0 ? j : 0;
        }
        if(j == 0){
            return i > 0 ? i : 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(word1[i - 1] == word2[j - 1]){
            return dp[i][j] = rec(word1, word2, i - 1, j - 1, dp);
        }
        return dp[i][j] = min(rec(word1, word2, i - 1, j, dp), rec(word1, word2, i, j - 1, dp)) + 1;
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        // vector<vector<int>> dp((int)word1.length() + 1, vector<int>(word2.length() + 1, 0));
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        for(int i = 0; i <= m; i++){
            prev[i] = i;
        }
        // for(int i = 0; i <= m; i++){
        //     dp[0][i] = i;
        // }
        for(int i = 1; i <= n; i++){
            curr[0] = i;
            for(int j = 1; j <= m; ++j){
                if(word1[i - 1] == word2[j - 1]){
                    curr[j] = prev[j-1];
                }else{
                    curr[j] = min(prev[j], curr[j-1]) + 1;
                }
            }
            prev = curr;
        }
        return prev[m];
        // return rec(word1, word2, (int) word1.length(), (int) word2.length(), dp);
    }
};