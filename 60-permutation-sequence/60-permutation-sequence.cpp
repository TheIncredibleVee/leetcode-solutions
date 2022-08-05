class Solution {
public:
    void factorial(vector<int> &dp, int n){
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1]*i;
        }
    }
    string getPermutation(int n, int k) {
        string s = "";
        for(int i = 0; i < n; ++i){
            s+=to_string(i+1);
        }
        string res = "";
        k-=1;
        vector<int> dp(n+1);
        factorial(dp, n);
        while(n > 0){
            res += s[k/dp[n-1]];
            s.erase(s.begin() + k/dp[n-1]);
            k %= dp[n-1];
            n--;
        }
        if(!s.empty()){
            res+=s;
        }
        return res;
    }
};