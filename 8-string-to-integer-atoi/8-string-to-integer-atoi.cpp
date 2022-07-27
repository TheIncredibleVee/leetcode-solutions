class Solution {
public:
    int myAtoi(string s) {
        bool sign = false;
        int res = 0;
        int n = s.length();
        int start = 0;
        int end = n-1;
        unordered_map<char, int> mp;
        mp['0'] = 0;
        mp['1'] = 1;
        mp['2'] = 2;
        mp['3'] = 3;
        mp['4'] = 4;
        mp['5'] = 5;
        mp['6'] = 6;
        mp['7'] = 7;
        mp['8'] = 8;
        mp['9'] = 9;
        // mp['-'] = -1;
        // mp['+'] = +1;
        // while(mp.find(s[start]) == mp.end()){
        //     start++;
        // }
        while(s[start] == ' '){
            start++;
        }
        if(s[start] == '-'){
            sign = !sign;
            start++;
        }
        else if(s[start] == '+'){
            start++;
        }
        if(mp.find(s[start]) == mp.end()){
            return 0;
        }
        while(s[start] == '0'){
            start++;
        }
        while(mp.find(s[end]) == mp.end()){
            end--;
        }
        cout<<end<<endl<<start<<endl;
        for(int i = start; i <= end; ++i){
            if(mp.find(s[i]) == mp.end()){
                break;
            }
            try{
                if(res > INT_MAX/10){
                    throw "OVERFLOW";   
                }
                res *= 10;
                int diff = INT_MAX - res;
                if(mp[s[i]] > diff){
                    throw "ERROR";
                }
                res += mp[s[i]];
            }
            catch(...){
                return sign? INT_MIN: INT_MAX;
            }
        }
        return sign? res * (-1): res;
    }
};