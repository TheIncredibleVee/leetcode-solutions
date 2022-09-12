class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int res = 0;
        int curr = 0;
        sort(tokens.begin(), tokens.end());
        int start = 0;
        int end = tokens.size() - 1;
        while(start <= end){
            if(power < tokens[start]){
                if(!curr){
                    break;
                }else{
                    curr--;
                    power += tokens[end--];
                }
            }else{
                curr++;
                power -= tokens[start++];
            }
            res = max(res, curr);
        }
        return res;
    }
};