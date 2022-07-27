class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        long long curr = 0;
        long long res = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < rows; ++i){
            for(int j = 1; j < cols; ++j){
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        for(int start_col = 0; start_col < cols; ++start_col){
            for(int end_col = start_col; end_col < cols; ++end_col){
                mp.clear();
                mp[0]++;
                curr = 0;
                for(int row = 0; row < rows; ++row){
                    curr += matrix[row][end_col] - (start_col > 0 ? matrix[row][start_col - 1] : 0);
                    if(mp.find(curr - target) != mp.end()){
                        res += mp[curr - target];
                    }
                    mp[curr]++;
                }
            } 
        }
        return res;
    }
};