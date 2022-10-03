class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int i = 0;
        int currMax, sum = 0;
        while(i < neededTime.size()){
            sum += neededTime[i];
            char c = colors[i];
            currMax = neededTime[i];
            while(colors[++i] == c){
                currMax = max(currMax, neededTime[i]);
                sum += neededTime[i];
            }
            res += currMax;
        }
        // for(char& c : colors){
        //     if(prev == c){
        //         curr += neededTime[i];
        //         currMax = max(neededTime[i], currMax);
        //     }else{
        //         res += (curr - currMax);
        //         curr = neededTime[i];
        //         currMax = neededTime[i];
        //     }
        //     prev = c;
        //     i++;
        // }
        return sum - res;
    }
};