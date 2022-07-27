class Solution {
    private:
        bool check(string &start, string &end){
            unordered_map<char, int> mp;
            for(char &c: start){
                mp[c]++;
            }
            for(char &c:end){
                mp[c]--;
                if(mp[c] == 0){
                    mp.erase(c);
                }
            }
            return mp.empty();
        }
public:
    bool canChange(string start, string target) {
        bool same = check(start, target);
        if(!same){
            return false;
        }
        int n = start.length();
        vector<int> vec1;
        vector<int> vec2;
        vec1.reserve(n);
        vec2.reserve(n);
        for(int i = 0; i < n;i++){ 
            if(start[i] != '_') {
                vec1.emplace_back(i);
            }
            if(target[i] != '_'){
                vec2.emplace_back(i);
            }
        }
        bool flag = true;
        for(int i = 0; i < vec1.size(); i++){ 
            if(start[vec1[i]] != target[vec2[i]]){ 
                flag = false;
            }
            else { 
                if(start[vec1[i]] == 'L'){ 
                    if(vec1[i] < vec2[i]){
                        flag = false;
                    }

                }else { 
                    if(vec1[i] > vec2[i]){
                        flag = false;
                    }

                }
            }

        }
        if(flag){
            return true;
        }
        return false;
    }
};