class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,int>> pq;
        int res = INT_MIN;
        for(int i = 0; i < n ; ++i){
            int x = points[i][0];
            int y = points[i][1];
            int sum = x + y;
            int diff = y - x;
            while(!pq.empty() && pq.top().second + k < x){
                pq.pop();
            }
            if(!pq.empty()){   
                int prevMax = pq.top().first;
                res = max(res, sum + prevMax);
            }
            pq.push({diff, x});
        }
        return res;
    }
};