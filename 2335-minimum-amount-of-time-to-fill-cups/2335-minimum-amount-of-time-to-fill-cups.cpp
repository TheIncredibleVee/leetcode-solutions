class Solution {
public:
    int fillCups(vector<int>& amount) {
        int res = 0;
        sort(amount.begin(), amount.end());
        for(auto &x: amount){
            res+=x; 
        }
        if(amount[0] + amount[1] > amount[2]){
            return res/2 + res%2;
        }
        return amount[2];
    }
};