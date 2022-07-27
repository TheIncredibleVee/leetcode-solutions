class Solution {
    private:
        int dfs(vector<vector<int>> &grid, int x, int y ){
           int res = 1;
            grid[x][y] = -1;
            if(y + 1 < grid[x].size() && grid[x][y + 1] == 1){
                res += dfs(grid, x, y + 1);
            }
            if(x + 1 < grid.size() && grid[x + 1][y] == 1){
                res += dfs(grid, x + 1, y);
            }
            if(y - 1 >= 0 && grid[x][y - 1] == 1){
                res += dfs(grid, x, y - 1);
            }
            if(x - 1 >= 0 && grid[x - 1][y] == 1){
                res += dfs(grid, x - 1, y);
            }
            return res;
        }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m;
        for(int i = 0; i < n; ++i){
            m = grid[i].size();
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }
};