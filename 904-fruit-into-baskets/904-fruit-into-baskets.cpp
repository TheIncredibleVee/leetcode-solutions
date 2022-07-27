class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int start = 0;
        int end = 0;
        int n = fruits.size();
        unordered_map<int, int> mp;
        while(end < n){
            // printf("%d %d\n", start, end);
            while(start < end && mp.size() > 2){
                mp[fruits[start]]--;
                if(mp[fruits[start]] == 0){
                    mp.erase(fruits[start]);
                }
                start++;
            }
            while(end < n && mp.size() <= 2){
                // printf("IN LOOP %d %d\n", end, mp.size());
                mp[fruits[end]]++;
                end++;
            }
            int currRes = end - start;
            if(mp.size() > 2){
                currRes--;
            }
            res = max(res, currRes);
            // printf("%d %d\n", start, end);
        }
        return res;
    }
};