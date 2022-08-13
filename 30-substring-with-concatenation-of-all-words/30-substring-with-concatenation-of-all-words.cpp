class Solution {
private:
    void func(string s, unordered_map<string, int> & mp, int wordSize, int totalWords, vector<int> & res, int offset){
        unordered_map<string, int> mp2;
        string temp = "";
        int n = s.length();
        int i = 0;
        for(i = 0; i < totalWords; ++i){
            temp = s.substr(i*wordSize, wordSize);
            // cout<<temp<<endl;
            mp2[temp]++;
        }
        int end = totalWords * wordSize;
        int j;
        for( j = wordSize; j + end - 1 < n ; j += wordSize){
            if(mp2 == mp){
                res.push_back(j - wordSize + offset );
            }
            temp = s.substr(j - wordSize, wordSize);
            mp2[temp]--; 
            if(mp2[temp] == 0){
                mp2.erase(temp);
            }
            temp = s.substr(j + end - wordSize, wordSize);
            mp2[temp]++;
        }
        if(mp2 == mp){
            res.push_back(j - wordSize + offset);
        }
    }
    
    int getNextIndex(string s, unordered_map<string, int> &mp, int wordSize, int n){
        unordered_map<string, int> mp2 = mp;
        string temp = "";
        for(int i = 0; i < n; i += wordSize){
            temp = s.substr(i, wordSize);
            if(mp2.find(temp) == mp2.end()){
                return i + 1;
            }
            mp2[temp]--;
            if(mp2[temp] == 0){
                mp2.erase(temp);
            }
        }
        return n;
    }
    bool check(string &s, unordered_map<string, int> &mp, int wordSize, int n){
        unordered_map<string, int> mp2 = mp;
        string temp = "";
        for(int i = 0; i < n; i += wordSize){
            temp = s.substr(i, wordSize);
            if(mp2.find(temp) == mp2.end()){
                return false;
            }
            mp2[temp]--;
            if(mp2[temp] == 0){
                mp2.erase(temp);
            }
        }
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordsN = words.size();
        int wordSize = words[0].length();
        unordered_map<string, int> mp;
        for(string &s: words){
            mp[s]++;
        }
        vector<int> res;
        string temp = "";
        int n = s.length();
        int i;
        int totalSize = wordsN * wordSize;
        // for(int i = 0; i< (n - totalSize + 1); i++){
        //     string temp = s.substr(i, totalSize);
        //     // int nextIdx = getNextIndex(temp, mp, wordSize, totalSize);
        //     // if(nextIdx == totalSize){
        //     //     res.push_back(i);
        //     // }
        //     // i += nextIdx;
        //     if(check(temp, mp, wordSize, totalSize)){
        //         res.push_back(i);
        //     }
        // }
        for(int i = 0; i < wordSize; ++i){
            func(s.substr(i), mp, wordSize, wordsN, res, i);
        }
        return res;
    }
};