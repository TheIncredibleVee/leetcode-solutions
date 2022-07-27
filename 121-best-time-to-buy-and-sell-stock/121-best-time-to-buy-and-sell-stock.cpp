class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if(n<=1)
        {
            return 0;
        }
        int maxprofit = 0;
        int minelement = arr[0];
        for(int i=1; i<n; ++i)
        {
            maxprofit = max(maxprofit, arr[i] - minelement);
            minelement = min(arr[i], minelement);
        }
        return maxprofit;
    }
};