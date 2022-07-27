class Solution {
public:
    int editDistance(string a, string b){
        int n = a.length();
        int m = b.length();
        vector<int> prev( m + 1, 0), curr(m + 1, 0);
        for(int i = 0; i <=m; ++i){
            prev[i] = i;
        }
        for(int i = 1; i <= n; ++i){
            curr[0] = i;
            for(int j = 1; j <= m; ++j){
                if(a[i - 1] == b[i - 1]){
                    curr[j] = prev[j - 1];
                }else{
                    curr[j] = 1 + curr[j - 1];
                }
            }
        }
        return prev[m];
    }
    
    bool isPred(string a, string b){
        int cnt = 0;
        int n = a.length();
        int m = b.length();
        if(m != n + 1){
            return false;
        }
        int j = 0;
        for(int i = 0 ; i < n && j < m; ++j){
            if(a[i] != b[j]){
                cnt++;
                if(cnt > 1){
                    return false;
                }
            }else{
                i++;
            }
        }
        return cnt <= 1;
    }
    
    int rec(vector<string> &words, int curr, int prev){
        if(prev < 0){
            return 0;
        }
        int res = rec(words, curr, prev - 1);
        if(curr == words.size() || isPred(words[prev], words[curr])){
            res = max(res , 1 + rec(words, prev, prev - 1));
        }
        return res;
    }
    int recTab(vector<string> &words, int curr, int prev, vector<vector<int>> &dp){
        // cout<<curr<<"\t"<<prev<<endl;
        if(prev == 0){
            return 0;
        }
        if(dp[curr][prev] != -1){
            return dp[curr][prev];
        }
        int res = recTab(words, curr, prev - 1, dp);
        if(curr > words.size() || isPred(words[prev - 1], words[curr - 1])){
            res = max(res, 1 + recTab(words, prev, prev - 1, dp));
        }
        return dp[curr][prev] = res;
    }
    int longestStrChain(vector<string>& words) {
//         sort(words.begin(), words.end(), [&](string a, string b)->bool{return a.length() < b.length();});
//         int n = words.size();
//         // for(auto x: words){cout<<x<<endl;}
//         vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));
//         int res = 1;
//         for(int i = 1; i <= n; ++i){
//             for(int j = 1; j <= n; ++i){
//                 dp[i][j] = dp[i][j - 1];
//                 if(isPred(words[j - 1], words[i - 1])){
//                     dp[i][j] = max(dp[i][j], 1 + dp[j][j - 1]);
//                 }
//             }
//         }
//         return dp[n][n];
//         // return recTab(words, n + 1, n, dp);
            
//         // return rec(words, n, n - 1);
//         return 0;
        vector<unordered_set<string>> W(17);
        for (auto word : words) 
            W[word.size()].insert(word);
        unordered_map<string, int> dp;
        int best = 1;
        for (int i = 16; i; i--) {
            if (W[i-1].empty()) continue;
            for (auto word : W[i]) {
                int wVal = dp[word] ? dp[word] : 1;
                for (int j = 0; j < word.size(); j++) {
                    string pred = word.substr(0,j) + word.substr(j+1);
                    int pVal = dp[pred] ? dp[pred] : 1;
                    if (W[i-1].find(pred) != W[i-1].end() && wVal >= pVal) {
                        dp[pred] = wVal + 1;
                        best = max(best, wVal + 1);
                    }
                }
            }
        }
        return best;
    }
};