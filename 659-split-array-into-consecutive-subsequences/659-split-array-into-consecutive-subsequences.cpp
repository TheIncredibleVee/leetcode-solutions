class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp, temp;
        for(int &x: nums){
            mp[x]++;
        }
        for(int &x: nums){
            if(mp.find(x) == mp.end()){
                continue;
            }
            mp[x]--;
            if(!mp[x]){
                mp.erase(x);
            }
            if(temp.find(x - 1) != temp.end()){
                temp[x-1]--;
                if(!temp[x-1]){
                    temp.erase(x-1);
                }
                temp[x]++;
            }else if(mp.find(x + 1) != mp.end() && mp.find(x + 2) != mp.end()){
                mp[x + 1]--;
                mp[x + 2]--;
                if(!mp[x + 1]){
                    mp.erase(x + 1);
                }
                if(!mp[x + 2]){
                    mp.erase(x + 2);
                }
                temp[x + 2]++;
            }else{
                return false;
            }
        }
        return true;
    }
};