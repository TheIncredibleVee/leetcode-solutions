class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int res;
        int h1 = abs(ax1 - ax2);
        int w1 = abs(ay1 - ay2);
        int h2 = abs(bx1 - bx2);
        int w2 = abs(by1 - by2);
        int total = (h1 * w1) + (h2 * w2);
        if(ax2 <= bx1 || ax1 >= bx2 || ay1 >=  by2 || by1 >= ay2){
            return total;
        }
        int btx = max(ax1, bx1);
        int bty = max(ay1, by1);
        int tpx = min(ax2, bx2);
        int tpy = min(ay2, by2);
        int h = abs(btx - tpx);
        int w = abs(bty - tpy);
        res = total - (h * w);
        return res;
    }
};