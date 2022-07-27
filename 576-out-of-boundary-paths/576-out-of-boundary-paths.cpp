class Solution {
private:
    long long mod = 1e9 + 7;
    long long rec(int m, int n, int x, int y, int mx, vector<vector<vector<long long>>> &dp){

        if(x >= m || x < 0 || y < 0 || y >= n){
            return 1;
        }
        if(mx == 0){
            return 0;
        }
        if(dp[x][y][mx] != -1){
            return dp[x][y][mx];
        }
        long long res = 0;
        res += rec(m, n, x - 1, y, mx - 1, dp) % mod;
        res += rec(m, n, x + 1, y, mx - 1, dp) % mod;
        res += rec(m, n, x, y - 1, mx - 1, dp) % mod;
        res += rec(m, n, x, y + 1, mx - 1, dp) % mod;
        return dp[x][y][mx] = res % mod;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<long long>> prev(m + 2, vector<long long>(n + 2, 0));
        vector<vector<long long>> curr(m + 2, vector<long long>(n + 2, 0));
        for(int move = 1; move <= maxMove; ++move){
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    long long up = i == 0 ? 1 : prev[i - 1][j];
                    long long down = i == m - 1 ? 1 : prev[i + 1][j];
                    long long left = j == 0 ? 1 : prev[i][j - 1];
                    long long right = j == n - 1 ? 1 : prev[i][j + 1];
                    curr[i][j] = up % mod + down % mod + left % mod + right % mod;
                    curr[i][j] %= mod;
                }
            }
            prev = curr;
        }
        return prev[startRow][startColumn];
        // return rec(m, n, startRow, startColumn, maxMove, dp);
    }
};