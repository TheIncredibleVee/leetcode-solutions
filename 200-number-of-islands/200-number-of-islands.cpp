class Solution {
public:
    void rec(vector<vector<char>> & grid, int x, int y, int row, int col){
        if(x >=row || x < 0 || y < 0 || y >= col || grid[x][y] != '1'){
            return;
        }
        grid[x][y] = '3';
        rec(grid, x + 1, y, row, col);
        rec(grid, x - 1, y, row, col);
        rec(grid, x, y + 1, row, col);
        rec(grid, x, y - 1, row, col);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == '1'){
                    rec(grid, i, j, (int)grid.size(), (int)grid[i].size());
                    res++;
                }
            }
        }
        return res;
    }
};