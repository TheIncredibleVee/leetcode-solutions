class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> greedy(n);
        for(int i = 0; i < n; ++i){
            greedy[i] = {efficiency[i], speed[i]};
        }
        sort(greedy.begin(), greedy.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        long long res = 0;
        for(int i = n - 1; i >= 0; i--){
            sum += greedy[i].second;
            pq.push(greedy[i].second);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            res = max(res, greedy[i].first * sum);
        }
        res = res % MOD;
        return (int) res;
    }
};