class Solution {
private:
    const long long mod = 1e9 + 7;
    int rec(vector<int> adj[], vector<vector<int>>& dp, int n, int source){
        if(n == 1){
            return 1;
        }
        if(dp[n][source] != -1){
            return dp[n][source];
        }
        int res = 0;
        for(int &child: adj[source]){
            res += (rec(adj, dp, n - 1, child) % mod);
            res %= mod;
        }
        return dp[n][source] = res % mod;
    }
    
public:
    int countVowelPermutation(int n) {
        int res = 0;
        vector<int> adj[5];
        adj[0] = vector<int>({1});
        adj[1] = vector<int>({0,2});
        adj[2] = vector<int>({0,1,3,4});
        adj[3] = vector<int>({2,4});
        adj[4] = vector<int>({0});
        vector<vector<int>> dp(n + 1, vector<int>(5, -1));
        for(int i = 0; i < 5; ++i){
            res += rec(adj, dp, n, i) % mod;  
            res %= mod;
        }
        return res % mod;
    }
};