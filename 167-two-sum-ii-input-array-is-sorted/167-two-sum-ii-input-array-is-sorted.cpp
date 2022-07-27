class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int high = numbers.size() - 1;
        int low = 0;
        vector<int> res;
        while(high > low){
            int currSum = numbers[low] + numbers[high];
            if(currSum == target){
                res.emplace_back(low + 1);
                res.emplace_back(high + 1);
                return res;
            }
            if(currSum > target){
                high--;
            }
            else{
                low++;
            }
        }
        return res;
    }
};