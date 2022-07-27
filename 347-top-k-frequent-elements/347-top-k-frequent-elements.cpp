class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();++i){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto x: mp){
            if(k>0){
                pq.push({x.second, x.first});
                k--;
            }
            else{
                auto temp = pq.top();
                int val = temp.second;
                int freq = temp.first;
                if(x.second > freq){
                    pq.pop();
                    pq.push({x.second, x.first});
                }else{
                    continue;
                }
            }
        }
        while(!pq.empty()){
            int val = pq.top().second;
            res.push_back(val);
            pq.pop();
        }
        return res;
    }
};