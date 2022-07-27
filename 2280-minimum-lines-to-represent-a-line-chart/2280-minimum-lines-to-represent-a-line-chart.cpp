class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if(stockPrices.size()== 1 ){
            return 0;
        }
        int res = 1;
        sort(stockPrices.begin(), stockPrices.end());
        for(int i=2;i<stockPrices.size(); i++){
            long long x2 = stockPrices[i][0];
            long long y2 = stockPrices[i][1];
            long long x1 = stockPrices[i-1][0];
            long long y1 = stockPrices[i-1][1];
            long long x0 = stockPrices[i-2][0];
            long long y0 = stockPrices[i-2][1];
            if((y2-y1)*(x1-x0) != (y1-y0) * (x2-x1)){
                res++;   
            }
        }
        return res;
    }
};