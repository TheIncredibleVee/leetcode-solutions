class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long int  sum = 0;
        for(auto &x: target){
            sum += x;
        }
        priority_queue<int> pq(target.begin(), target.end());
    while(pq.top()!= 1){
            auto curr = pq.top();
            pq.pop();
            sum -= curr;    
            if(curr<= sum || sum < 1){
                return false;
            }
            curr %= sum;
            sum += curr;
            pq.push(curr ? curr : sum);
        }
        return true;
    }
};