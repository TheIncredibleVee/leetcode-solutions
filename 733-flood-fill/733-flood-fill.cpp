class Solution {
public:
    void rec(vector<vector<int>>& image, int sr, int sc, int r, int c, int newColor, int prevColor){
        if(sr >= r || sc >= c || sr < 0 || sc < 0 || image[sr][sc] != prevColor || image[sr][sc] == newColor){
            return;
        }
        image[sr][sc] = newColor;
        rec(image, sr + 1, sc, r, c, newColor, prevColor);
        
        rec(image, sr - 1, sc, r, c, newColor, prevColor);
        
        rec(image, sr, sc + 1, r, c, newColor, prevColor);
        
        rec(image, sr, sc - 1, r, c, newColor, prevColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int r = image.size();
        int c = image[0].size();
        int prevColor = image[sr][sc];
        rec(image, sr, sc, r, c, newColor, prevColor);
        return image;
    }
};