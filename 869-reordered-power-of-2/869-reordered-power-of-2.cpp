class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n == 1){
            return true;
        }
        unordered_map<int,int> mp;
        int temp = n;
        while(temp){
            mp[temp%10]++;
            temp /= 10;
        }
        for(int i = 0; i < 31; ++i){
            int val = 1<<i;
            unordered_map<int,int> mp2;
            mp2.clear();
            while(val){
                mp2[val % 10]++;
                val /= 10;
            }
            if(mp2 == mp){
                
                
                return true;
            }
        }
        return false;
    }
};