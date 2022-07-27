class Solution {
public:
    bool isPalindrome(string s){
        int i=0;
        int j=s.length()-1;
        while(j>=i){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    
    void rec(string s, vector<vector<string>> &res, vector<string> &curr, int idx, int N){
        if(idx == N){
            // // cout<<"YEAH\n";
            // for(auto x: curr){
            //     // cout<<x<<"\t"<<isPalindrome(x)<<endl;
            //     if(!isPalindrome(x))
            //         return;
            // }
            res.push_back(curr);
        }
        
        for(int i = idx; i<N; ++i){
            string temp = s.substr(idx, i - idx + 1);
            if(!isPalindrome(temp)){
                continue;
            }
            curr.push_back(temp);
            rec(s, res, curr, i + 1, N);
            curr.pop_back();
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        int N = s.length();
        rec(s, res, curr, 0, N);
        return res;
    }
};