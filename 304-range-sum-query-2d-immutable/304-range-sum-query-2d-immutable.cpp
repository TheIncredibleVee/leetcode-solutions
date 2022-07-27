class NumMatrix {
    private:
         vector<vector<int>> presum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        presum = vector<vector<int>>(r + 1, vector<int>(c + 1, 0));
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                presum[i+1][j+1] = matrix[i][j] + presum[i][j + 1] + presum[i + 1][j] - presum[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return presum[row2 + 1][col2 + 1] + presum[row1][col1] - presum[row1][col2 + 1] - presum[row2 + 1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */