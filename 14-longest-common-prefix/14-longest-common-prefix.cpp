class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.empty()){
            return res;
        }
        if(strs.size() == 1){
            return strs[0];
        }
        bool flag = true;
        int n = strs.size();
        int curr = 0;
        while(flag && curr < strs[0].size()){
            for(int i = 0; i < n;++i){
                if(strs[i].empty()){
                    return "";
                }
                if(strs[i][curr] != strs[0][curr]){
                    flag = false;
                    break;
                }
            }
            
            if(flag){
                res += strs[0][curr];
            }
            curr++;    
        }
        return res;
    }
};