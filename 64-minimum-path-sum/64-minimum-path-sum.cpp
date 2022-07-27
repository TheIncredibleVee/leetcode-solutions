class Solution {
    private: 
        int rec(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
            if(i >= grid.size() || j >= grid[0].size()){
                return -1;
            }
            if(dp[i][j] != -1){
                return dp[i][j];
            }
            if(i == grid.size() - 1 && j == grid[0].size() - 1){
                return dp[i][j] = grid[i][j];
            }
            int res = INT_MAX;
            int right = rec(grid, i + 1, j, dp);
            int down = rec(grid, i, j + 1, dp);
            if(right != -1){
                res = min(res, right);
            }
            if(down != -1 ){
                res = min(res, down);
            }
            return dp[i][j] = res + grid[i][j];
        }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return rec(grid, 0, 0, dp);
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(i == 0 && j == 0 ){
                    dp[0][0] = grid[0][0]; 
                }else {
                    int res = INT_MAX;
                    if(i > 0){
                        res = min(res, dp[i - 1][j]);
                    }
                    if(j > 0){
                        res = min(res, dp[i][j - 1]);
                    }
                    dp[i][j] = res + grid[i][j];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};