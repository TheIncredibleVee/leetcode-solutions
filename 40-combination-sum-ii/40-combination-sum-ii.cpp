class Solution {
public:
    void rec(vector<int> &arr, vector<vector<int>> &res, vector<int> &curr, int idx, int N, int target){
        if(target == 0){
            res.push_back(curr);
        }
        if(target < 0){
            return;
        }
        for(int i = idx; i < N;++i){
            if(target < arr[i]){
                return;
            }
            if( i == idx || arr[i] != arr[i-1]){
                curr.push_back(arr[i]);
                rec(arr, res, curr, i+1, N, target - arr[i]);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        int N = candidates.size();
        rec(candidates, res, curr, 0, N, target);
        return res;
    }
};