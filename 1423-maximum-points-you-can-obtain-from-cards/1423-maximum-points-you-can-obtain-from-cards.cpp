class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int n = cardPoints.size();
        int restLen = n - k;
        int res = 0;
        for(int i = 0; i < restLen; ++i){
            res += cardPoints[i];
        }
        int minSum = res;
        for(int i = restLen; i < n; ++i){
            res -= cardPoints[i - restLen];
            res += cardPoints[i];
            minSum = min(minSum, res);
        }
        return sum - minSum;
    }
};