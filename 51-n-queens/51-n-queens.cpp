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
        // for(int i=0;i<s[0].length();++i){
        //     if(s[i][x]=='Q'){
        //         return false;
        //     }
        // }
        // for(int j=0; j<s[0].length(); ++j){
        //     if(s[y][j] == 'Q'){
        //         return false;
        //     }
        // }
        // for(int i=x, j=y;i<s[0].length() && j<s[0].length();++i, j++){
        //     if(s[i][j]=='Q'){
        //         return false;
        //     }
        // }
        // for(int i=x, j=y;i>=0 && j>=0;i--, j--){
        //     if(s[i][j]=='Q'){
        //         return false;
        //     }
        // }
        // for(int i=x, j=y;i<s[0].length() && j>=0;++i, j--){
        //     if(s[i][j]=='Q'){
        //         return false;
        //     }
        // }
        // for(int i=x, j=y;i>=0 && j<s[0].length();i--, j++){
        //     if(s[i][j]=='Q'){
        //         return false;
        //     }
        // }
        return true;
    }
    
    
    void rec(vector<vector<string>> &res, vector<string> &curr, int x, int n){
        if(x == n){
            // cout<<x<<"\t"<<y<<"\t"<<q<<endl;
            res.push_back(curr);
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
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n,'.');
        vector<string> curr(n,s);
        rec(res, curr, 0, n);
        return res;
    }
};