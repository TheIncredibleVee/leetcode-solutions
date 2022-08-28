class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        if(!n){
            return mat;
        }
        int m = mat[0].size();
        for(int starti = 0; starti < n; ++starti){
            int startj = 0;
            int tempi = starti;
            vector<int> temp;
            while(tempi < n && startj < m){
                temp.push_back(mat[tempi++][startj++]);
            }
            sort(temp.begin(), temp.end());
            startj = 0;
            tempi = starti;
            int k = 0;
            while(tempi < n && startj < m){
                mat[tempi++][startj++] = temp[k++];
            }
        }
        for(int startj = 0; startj < m; ++startj){
            int starti = 0;
            int tempj = startj;
            vector<int> temp;
            while(tempj < m && starti < n){
                temp.push_back(mat[starti++][tempj++]);
            }
            sort(temp.begin(), temp.end());
            starti = 0;
            tempj = startj;
            int k = 0;
            while(tempj < m && starti < n){
                mat[starti++][tempj++] = temp[k++];
            }
        }
        return mat;
    }
};