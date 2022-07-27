class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int start, end;
        int n = s.length();
        int maxLen = 0;
        for(int i = 0; i < n; ++i){
            int start = i - 1;
            int end = i + 1;
            while(start>= 0 && s[i]==s[start]){
                start--;
            }
            while(end < n && s[i]==s[end]){
                end++;
            }
            while(start>= 0 && end < n && s[start] == s[end]){
                start--;
                end++;
            }
            if(maxLen < end - start - 1){
                maxLen = end - start - 1;
                res = s.substr(start + 1, maxLen);
            }
        }
        return res;
    }
};