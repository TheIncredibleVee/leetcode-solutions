class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 ){
            return false;
        }
        int temp = x;
        long long res = 0;
        while(temp){
            int digit = temp %10;
            res = res * 10 + digit; 
            temp /= 10;
        }
        return res == x;
    }
};