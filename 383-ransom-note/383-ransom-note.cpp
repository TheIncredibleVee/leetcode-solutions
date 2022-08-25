class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();
        if(n == m){
            sort(ransomNote.begin(), ransomNote.end());
            sort(magazine.begin(), magazine.end());
            return magazine == ransomNote;
        }
        if(n > m){
            return false;
        }
        unordered_map<char,int> mp, mp2;
        for(auto &x: ransomNote){
            mp[x]++;
        }
        for(auto &x: magazine){
            mp2[x]++;
        }
        for(auto &x: mp2){
            if(mp[x.first] > x.second){
                return false;
            }else{
                mp.erase(x.first);
            }
        }
        return mp.empty();
    }
};