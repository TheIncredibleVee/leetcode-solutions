class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        vector<pair<int, int>> knapsack;
        knapsack.reserve(n);
        for(auto &x: boxTypes){
            knapsack.emplace_back(x[1], x[0]);
        }
        sort(knapsack.begin(), knapsack.end(), [&](pair<int, int> a, pair<int,int> b)->bool{return a.first > b.first;});
        int res = 0;
        int i = 0;
        while(truckSize > 0 && i < n){
            int weight = knapsack[i].second;
            int value = knapsack[i].first;
            if(truckSize > weight){
                truckSize -= weight;
                res += value * weight;
            }else{
                res += truckSize * value;
                truckSize = 0;
            }
            i++;
        }
        return res;
    }
};