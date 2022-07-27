class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        int res = -1;
        for(int i = 0; i < n - m + 1; ++i){
            if(haystack[i] == needle[0] && haystack.substr(i, m) == needle){
                return i;
            }
        }
        return res;
    }
};