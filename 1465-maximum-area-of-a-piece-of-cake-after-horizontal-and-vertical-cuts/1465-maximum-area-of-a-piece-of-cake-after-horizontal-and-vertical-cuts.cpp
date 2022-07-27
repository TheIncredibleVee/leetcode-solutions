class Solution {
    const long long MOD = 1e9 + 7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long res;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        int horiMax = horizontalCuts[0];
        int totalHeight = horizontalCuts.size();
        for(int i = 1; i < totalHeight; ++i){
            horiMax = max(horiMax, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        horiMax = max(horiMax, h - horizontalCuts[totalHeight - 1]);
        sort(verticalCuts.begin(), verticalCuts.end());
        int verMax = verticalCuts[0];
        int totalVer = verticalCuts.size();
        for(int i = 1; i < totalVer; ++i){
            verMax = max(verMax, verticalCuts[i] - verticalCuts[i - 1]);
        }
        verMax = max(verMax, w - verticalCuts[totalVer - 1]);
        res = verMax % MOD * horiMax % MOD;
        res %= MOD;
        return (int)res;
    }
};