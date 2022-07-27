class Solution {
public:
    int removePalindromeSub(string s) {
        string rev = s;
        reverse(s.begin(), s.end());
        if(rev == s){
            return 1;
        }else{
            return 2;
        }
    }
};