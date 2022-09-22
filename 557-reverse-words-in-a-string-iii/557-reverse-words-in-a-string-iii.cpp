class Solution {
public:
    string reverseWords(string s) {
        string res= "", curr= "";
        for(char &c: s){
            if(c == ' '){
                reverse(curr.begin(), curr.end());
                res += curr + " ";
                curr = "";
            }else{
                curr += c;
            }
        }
        reverse(curr.begin(), curr.end());
        res += curr;
        return res;
    }
};