class Solution {
private:
    const long long mod = 1e9 + 7;
    int rec(int pos, vector<int>& arr, unordered_map<int, int> & st, int n, vector<int> & dp){
        if(dp[pos] != -1){
            return dp[pos];
        }
        long long res = 1;
        int root = arr[pos];
        for(int i = 0; i < n; ++i){
            if(root % arr[i] == 0 && st.find(root/arr[i])!= st.end()){
                int j = st[root/ arr[i]];
                res += ((rec(i, arr, st, n, dp) % mod) * (rec(j, arr, st, n,dp )% mod))% mod;
                res %= mod;
            }
        }
        return dp[pos] = (res % mod);
        
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        unordered_map<int, int> st;
        vector<int> dp(n + 1, -1);
        for(int i = 0; i < n; ++i){
            st.insert({arr[i], i});
        }
        for(int i = 0; i < n; ++i){
            res += (rec(i, arr, st, n,dp)% mod);
            res %= mod;
        }
        return res;
    }
};