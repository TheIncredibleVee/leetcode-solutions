class Solution {
private:
    bool check(string& source, string& pattern, int n){
        unordered_map<char, char> mp;
        unordered_set<char> st;
        for(int i = 0; i < n; ++i){
            char s = source[i];
            char p = pattern[i];
            if(mp.find(s) != mp.end()){
                if(mp[s] != p)
                    return false;
            }else{
                if(st.find(p) != st.end()){
                    return false;
                }
                mp[s] = p;
                st.insert(p);
            }
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        res.reserve(words.size());
        int n = pattern.length();
        for(string& word: words){
            if(check(word, pattern, n)){
                res.emplace_back(word);
            }
        }
        return res;
    }
};