class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp;
        if(n == 1){
            return "1";
        }
        dp.push_back("1");
        dp.push_back("11");
        for(int i = 2; i < n ; ++i){
            string curr = "";
            string temp = dp.back();
            int cnt = 0;
            char c = temp[0];
            for(int j = 0; j < temp.length();){
                while(j < temp.length() && temp[j] == c){
                    j++;
                    cnt++;
                }
                curr += to_string(cnt) + c;
                if(j < temp.length() ){
                    c = temp[j];
                    cnt = 0;
                }
            }
            dp.push_back(curr);
        }
        return dp.back();
    }
};