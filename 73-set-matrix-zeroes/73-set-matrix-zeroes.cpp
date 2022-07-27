class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isCol=false;
        for(int i=0;i<matrix.size();++i){
            if(matrix[i][0]==0){
                isCol=true;
            }
            for(int j=1;j<matrix[i].size();++j){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<matrix.size();++i){

            for(int j=1;j<matrix[i].size();++j){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i=0;i<matrix[0].size();++i){
                matrix[0][i]=0;
            }
        }
        if(isCol){
            for(int i=0;i<matrix.size();++i){
                matrix[i][0]=0;
            }
        }
    }
    
    /*
        Alternate Approach using set as extra Space
    */
    // void setZeroes(vector<vector<int>>& matrix) {
        // vector<pair<int,int>> zeros;
        // for(int i=0;i<matrix.size();++i){
        //     for(int j=0;j<matrix[i].size();j++){
        //         if(matrix[i][j]==0){
        //             zeros.push_back({i,j});
        //         }
        //     }
        // }
        // set<int> row, col;
        // for(auto x:zeros){
        //     row.insert(x.first);
        //     col.insert(x.second);
        // }
        // for(auto x: row){
        //     for(int i=0;i<matrix[x].size();++i){
        //         matrix[x][i]=0;
        //     }
        // }
        // for(auto x:col){
        //     for(int j=0;j<matrix.size();j++){
        //         matrix[j][x]=0;
        //     }
        // }
    // }   
};