class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        if( n == 1){
            return res;
        }
        for(int i = 0; i < n - 1; ++i){
            int startx = points[i][0];
            int starty = points[i][1];
            int endx = points[i + 1][0];
            int endy = points[i + 1][1];
            int xdif = abs(endx - startx);
            int ydif = abs(endy - starty);
            res += max(xdif, ydif);
        }
        return res;
    }
};