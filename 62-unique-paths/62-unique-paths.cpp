class Solution {
    private:
        const long long MOD = 2 * 1e9;
public:
    int uniquePaths(int m, int n) {
        long long res = 1;
        n--;
        m--;
        if(n > m){
            swap(n, m);
        }
        int j = 1;
        for(int i = m + 1; i <= (m+n); ++i){
            res *= i;
            res /= j;
            res %= MOD;
            j++;
        }
        return res;
    }
};