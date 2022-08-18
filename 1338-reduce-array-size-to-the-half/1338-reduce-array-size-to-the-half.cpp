class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int res = 0;
        int curr_size = 0;
        int n = arr.size();
        unordered_map<int,int> mp;
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int& x: arr){
            mp[x]++;
            mx = max(x, mx);
            mn = min(x, mn);
        }
        priority_queue<int> pq;
        for(pair<int, int> x: mp){
            pq.push(x.second);
        }
        while(!pq.empty()){
            curr_size += pq.top();
            pq.pop();
            res++;
            if(curr_size >= (n + 1)/2){
                break;
            }
        }
        return res;
    }
};