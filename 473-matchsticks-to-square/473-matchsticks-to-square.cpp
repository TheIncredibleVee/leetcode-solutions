#pragma GCC optimise ("Ofast")
static auto x= []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
    bool rec(vector<int>& matchsticks, vector<int> &sides, int k, int end, int sum){
        if(end < 0){
            for(int &x: sides){
                if(x != sum){
                    return false;
                }
            }
            return true;
        }
        for(int i = 0; i < k; ++i){
            sides[i] += matchsticks[end];
            if(sides[i] <= sum){
                if(rec(matchsticks, sides, k, end - 1, sum)){
                    return true;
                }
            }
            sides[i] -= matchsticks[end];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        long long sum = 0;
        unordered_map<int, int> mp;
        int n = matchsticks.size();
        int mx = INT_MIN;
        for(int &matchstick: matchsticks){
            sum += matchstick;
            mp[matchstick]++;
            mx = max(mx, matchstick);
        }
        if(sum % 4 || mx > sum / 4){
            return false;
        }
        long long side = sum / 4;
        sort(matchsticks.begin(), matchsticks.end());
        int sidesRem = 4;
        int start = 0;
        int end = n - 1;
        while(end >= 0 && matchsticks[end] == side){
            end--;
            sidesRem--;
        }
        if(!sidesRem){
            if(end == -1){
                return true;
            }else{
                return false;
            }
        }
        vector<int> sides(sidesRem, 0);
        return rec(matchsticks, sides, sidesRem, end, side);
    }
};
