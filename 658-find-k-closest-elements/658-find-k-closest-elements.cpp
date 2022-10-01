class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        res.reserve(k);
        int n = arr.size();
        int i;
        if(x >= arr.back()){
            i = n - 1;
            while(k--){
                res.emplace_back(arr[i--]);
            }
            reverse(res.begin(), res.end());
            return res;
        }
        if(x <= arr[0]){
            i = 0;
            while(k--){
                res.emplace_back(arr[i++]);
            }
            return res;
        }
        i = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        int j = i - 1;
        while(k--){
            if(j >= 0 && abs(arr[j] - x) <= abs(arr[i] - x)){
                res.emplace_back(arr[j--]);
            }else{
                res.emplace_back(arr[i++]);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};