class Solution {
public:
    bool isPossible(vector<string> &s, int x, int y){
        for(int i = x; i>=0;i--){
            if(s[i][y] == 'Q'){
                return false;
            }
        }
        for(int i = x, j = y; i>=0 && j>=0; i--,j--){
            if(s[i][j]== 'Q'){
                return false;
            }
        }
        for(int i = x, j = y; i>=0 && j<s.size() ;j++, i--){
            if(s[i][j]== 'Q'){
                return false;
            }
        }
        return true;
    }
    
    
    void rec(int &res, vector<string> &curr, int x, int n){
        if(x == n){
            res++;
            return;
        }
        for(int i = 0; i < n; ++i){
            if(isPossible(curr, x, i)){
                curr[x][i] = 'Q';
                rec(res, curr, x + 1, n);
                curr[x][i] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        int res = 0;
        string s(n,'.');
        vector<string> curr(n,s);
        rec(res, curr, 0, n);
        return res;
    }
};