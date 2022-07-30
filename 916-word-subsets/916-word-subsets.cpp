class Solution {
private:
    string convert(vector<string>& words){
        string ans = "";
        unordered_map<char, int> res;
        for(string& word: words){
            unordered_map<char, int> temp;
            for(char& c : word){
                temp[c]++;
            }
            for(auto &pair: temp){
                char key = pair.first;
                int value = pair.second;
                if(res.find(key) != res.end()){
                    res[key] = max(res[key], value);
                }else{
                    res[key] = value;
                }
            }
        }
        for(auto& pair: res){
            char key = pair.first;
            int value  = pair.second;
            while(value--){
                ans += key;
            }
        }
        return ans;
    }
    
    bool check(string& subset, string& word){
        unordered_map<char, int> mp;
        for(char& c: subset){
            mp[c]++;
        }
        for(char& c: word){
            if(mp.find(c) != mp.end()){
                mp[c]--;
                if(!mp[c]){
                    mp.erase(c);
                }
            }
            if(mp.empty()){
                return true;
            }
        }
        return mp.empty();
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        res.reserve(words1.size());
        string b = convert(words2);
        for(string& word:words1){
            if(check(b, word)){
                res.emplace_back(word);
            }
        }
        return res;
    }
};