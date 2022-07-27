class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        if(n < 4){
            return res;
        }
        int one,two,three,four;
        for(int i = 0; i < n - 3; ++i){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            one = nums[i];
            for(int j = i + 1; j < n - 2; ++j){
                if(j > i +1 && nums[j] == nums[j - 1]){
                    continue;
                }
                two = nums[j];
                three = j + 1;
                four = n - 1;
                while(three < four){
                    long long sum = (long long)nums[three] + (long long )nums[four] + (long long)one + (long long)two;
                    if(sum == target){
                        vector<int> curr;
                        curr.reserve(4);
                        curr.emplace_back(one);
                        curr.emplace_back(two);
                        curr.emplace_back(nums[three]);
                        curr.emplace_back(nums[four]);
                        res.emplace_back(curr);
                        three++;
                        four--;
                        while(three < four && nums[three] == nums[three - 1]){
                            three++;
                        }
                        while(three < four && nums[four] == nums[four + 1]){
                            four--;
                        }
                    }else if(sum > target){
                        four--;
                    }else{
                        three++;
                    }
                }
            }
        }
        return res;
    }
};