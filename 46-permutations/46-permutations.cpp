class Solution {
public:
    void rec(vector<int> &arr, vector<vector<int>> &res, int idx, int N){
        if(idx == N){
            res.push_back(arr);
            return;
        }
        for(int i = idx; i < N; ++i){
            swap(arr[i], arr[idx]);
            rec(arr, res, idx + 1, N);
            swap(arr[idx], arr[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        rec(nums, res, 0, (int)nums.size());
        return res;
    }
};