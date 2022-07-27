class Solution {
private:
    long long mod = 1e9 + 7;
    int countInversions(vector<int> &arr, int l, int r, int mx){
        if(l >= r){
            return 0;
        }
        int res = 0;
        int mid = l + ((r - l)/2);
        res += countInversions(arr, l, mid, mx) + countInversions(arr, mid + 1, r, mx);
        if(res > mx){
            return 1005;
        }
        vector<int> temp(r - l  + 1);
        int i = l; 
        int j = mid + 1;
        int k = 0;
        while(i <= mid && j <= r){
            if(arr[j] < arr[i]){
                res += mid - i + 1;
                if(res > mx ){
                    return 1005;
                }
                temp[k++] = arr[j++];
            }else{
                temp[k++] = arr[i++];
            }
        }
        while(i <= mid){
            temp[k++]= arr[i++];
        }
        while(j <= r){
            temp[k++] = arr[j++];
        }
        k = 0;
        for(int i = l; i <= r; ++i){
            arr[i] = temp[i - l];
        }
        return res;
    }
    
    void rec(vector<int> &arr, int &res, int idx, int n, int k ){
        if(idx == n){
            vector<int> temp(arr.begin(), arr.end());
            if(countInversions(temp, 0, n - 1, k) == k){
                res++;
            }
            return;
        }
        for(int j = idx; j < n; ++j){
            swap(arr[idx], arr[j]);
            rec(arr, res, idx + 1, n, k);
            swap(arr[idx], arr[j]);
        }
        return;
    }
public:
    int dprec(int n, int k, vector<vector<long long>> &dp){
        if(n == 0){
            return 0;
        }
        if(k == 0){
            return 1;
        }
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        int res = 0;
        for(int i = 0; i < min(k + 1, n); ++i){
            res += dprec(n - 1, k - i, dp) % mod;
        }
        return dp[n][k] = res % mod;
    }
    
    int kInversePairs(int n, int k) {
        vector<long long> curr(k + 1, 0);
        vector<long long> prev(k + 1, 0);
        for(int len = 1; len <= n; ++len){
            for(int pair = 0; pair <= k; ++pair){
                if(pair == 0){
                    curr[pair] = 1;
                }else{
                    curr[pair] = curr[pair - 1] % mod + (prev[pair]  - (len <= pair ? prev[pair - len]: 0)) % mod;
                }
            }
            prev = curr;
        }
        return (curr[k] + mod - (k > 0 ? curr[k - 1] : 0)) % mod; 
        // int res = 0;
        // vector<int> arr(n);
        // for(int i = 0; i < n ;++i){
        //     arr[i] = i + 1;
        // }
        // rec(arr, res, 0 , n, k);
        // return res;
        // vector<vector<long long>> dp(n + 2, vector<long long>(k + 2 , -1));
        // return dprec(n, k, dp);
    }
};