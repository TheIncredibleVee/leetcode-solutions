class Solution {
public:
    int minDeletions(string s) {
        int res = 0;
        unordered_map<char, int> mp;
        for(auto &x: s){
            mp[x]++;
        }
        unordered_set<int> st;
        for(auto &x: mp){
            int freq = x.second;
            char c = x.first;
            while(st.find(freq) != st.end()){
                freq--;
                res++;
            }
            if(freq != 0){
                st.insert(freq);
            }
        }
        return res;
    }
};