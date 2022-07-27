class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int startx = 0;
        int starty = 0;
        int endx = n - 1;
        int endy = n - 1;
        int num = 1;
       while(startx <= endx || starty <= endx){
           for(int i = starty; i <= endy; ++i){
               res[startx][i] = num++;
           }
           startx++;
           for(int i = startx; i <= endx; ++i){
                res[i][endy] = num++;
            }
            endy--;
            for(int i = endy; i >= starty; --i){
                res[endx][i] = num++;
            }
            endx--;
            for(int i = endx; i >= startx; --i){
                res[i][starty]= num++;
            }
            starty++;
       }
        return res;
    }
};