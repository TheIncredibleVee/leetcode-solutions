class Solution {
    private: 
        int count(int n){
            return (n*(n + 1)) /2;
        }
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int res = 0;
        int up = 0;
        int down = 0;
        int slope = 0;
        for(int i = 1; i < n; ++i){
            int newSlope = ratings[i] - ratings[i - 1];
            if((newSlope >= 0 && slope < 0) || (newSlope == 0 && slope > 0) ){
                res += count(up) + count(down) + max(up, down);
                up = 0;
                down = 0;
            }
            if(newSlope > 0){
                up++;
            } else if(newSlope < 0){
                down++;
            }else{
                res++;
            }
            slope = newSlope;
        }
        res += count(up) + count(down) + max(up, down) + 1;
        return res;
    }
};