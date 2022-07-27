class Solution {
public:
    bool isPossible(vector<vector<char>> &board, int x, int y, char val){
        int n = board.size();
        for(int i = 0; i < n; ++i){
            if(board[x][i] == val || board[i][y] == val){
                return false;
            }
        }
        // int startx = (x / sqrt(n));
        // startx *= sqrt(n);
        // int endx = startx + sqrt(n) - 1 ;
        // int starty  = (y / sqrt(n));
        // starty *= sqrt(n);
        // int endy = starty + sqrt(n) - 1 ;
        int row = x - x % 3;
        int col = y - y % 3;
        for(int i = 0; i <= 3 - 1; ++i){
            for(int j = 0 ; j<= 3 - 1; ++j){
                if(board[i + row][j + col] == val){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board, int n, int i, int j){
        if(i >= n){
            return true;
        }
        if(j == n){
            return solve(board, n, i + 1 ,0);
        }
        if(board[i][j] != '.'){
            return solve(board, n, i, j + 1);
        }
        for(int val = 1; val <= n; val++){
            if(isPossible(board, i, j, '0' + val)){
                board[i][j] = '0' + val;
                if(solve(board, n, i, j+1))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solve(board, n, 0, 0);
    }
};