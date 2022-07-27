class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0){
            return 0;
        }
        int res = triangle[0][0];
        if(n == 1){
            return res;
        }
        vector<int> next(n);
        for(int i = 0; i < n; ++i){
            next[i] = triangle[n-1][i];
        }
        for(int i = n-2; i >= 0; --i){
            vector<int> curr(n);
            for(int j = i; j >= 0; --j){
                curr[j] = triangle[i][j] + min(next[j], next[j + 1]);
            }
            next = curr;
        }
        return next[0];
    }
};