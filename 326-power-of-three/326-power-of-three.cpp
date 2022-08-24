class Solution {
public:
    bool isPowerOfThree(int n) {
        if(!n){
            return false;
        }
        if(n ==1){
            return 1;
        }
        if(n%3){
            return false;
        }
        while(n != 1){
            n/=3;
            if(n %3 && n !=1){
                return false;
            }
        }
        return true;
    }
};