class Solution {
public:
    string reverseWords(string s) {
        string res ="";
        int n = s.length();
        string currWord = "";
        bool flag = false;
        for(int i =0; i<n;++i){
            if(s[i]==' '){
                flag = true;
                if(currWord=="" || currWord == " "){
                    currWord = "";
                    continue;
                }
                if(res!="") currWord+=" ";
                res = currWord + res;
                currWord = "";
                // while(s[i] == ' '){
                //     i++;
                // }
            }else{
                currWord += s[i];
            }
        }
        if(!flag){
            return s;
        }
        if(currWord!="" && currWord != " "){
              res = currWord + " " + res;
        }
        return res;
    }
};