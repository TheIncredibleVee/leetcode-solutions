class Solution {
public:
    int minPartitions(string n) {
        int res = INT_MIN;
        for(auto &x: n){
            res = max(res, x - '0');
        }
        return res;
    }
};