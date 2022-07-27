class Solution {
public:
    void rec(vector<int> arr, set<vector<int>> &res, int idx, int N, vector<int> &temp){
        if(idx == N){
            vector<int> to_push(temp.begin(), temp.end());
            sort(to_push.begin(), to_push.end());
            res.insert(to_push);
            return;
        }
        rec(arr, res, idx + 1, N, temp);
        temp.push_back(arr[idx]);
        rec(arr, res, idx + 1, N, temp);
        temp.pop_back();
    }
    void rec(vector<int> &arr, vector<vector<int>> &res, int idx, int N, vector<int> &curr){
        res.push_back(curr);
        for(int i = idx;i!=N;++i){
            if(i == idx || arr[i] != arr[i-1]){
                curr.push_back(arr[i]);
                rec(arr, res, i+1, N, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        rec(nums, res, 0, N, temp);
        return res;
    }
};