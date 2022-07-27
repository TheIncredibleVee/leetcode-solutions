class Solution {
public:
    void rec(vector<int> &arr, vector<vector<int>> &res, vector<int> &curr, int idx, int N, int target){
        if(target == 0){
            res.push_back(curr);
        }
        if(target < 0 ){
            return;
        }
        for(int i = idx; i<N;++i){
            if(target < arr[i]){
                return;
            }
            curr.push_back(arr[i]);
            rec(arr, res, curr, i, N, target- arr[i]);
            curr.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        int N = candidates.size();
        rec(candidates, res, curr, 0, N, target);
        return res;
    }
};