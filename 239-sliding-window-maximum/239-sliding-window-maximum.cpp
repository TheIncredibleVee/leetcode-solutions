class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // stack<int> s;
        // int currMax = k-1;
        // for(int i = k - 1; i >= 0;--i){
        //     if(nums[currMax] < nums[i]){
        //         currMax = i;
        //     }
        //     if(s.empty() || nums[s.top()] < nums[i])
        //         s.push(i);
        // }
        // vector<int> res;
        // res.push_back(nums[currMax]);
        // int n =nums.size();
        // for(int i = k; i< n; ++i){
        //     while(!s.empty() && ( i-k >= s.top() || nums[i] >= nums[s.top()])){
        //         s.pop();
        //     }
        //     if(currMax <= i-k){
        //         if(s.empty()){
        //             currMax = i;
        //         }else{
        //             currMax = s.top();
        //         }
        //     }
        //     if(s.empty() || nums[s.top()] < nums[i]){
        //         currMax = i;
        //     }
        //     s.push(i);
        //     res.push_back(nums[currMax]);
        // }
        
        int n = nums.size();
        vector<int> res;
        deque<int> dq;
        for(int i = 0; i < k; ++i){
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        for(int i = k; i < n; ++i){
            if(!dq.empty() && dq.front() == i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        // for (int i=0; i<nums.size(); i++) {
        //     if (!dq.empty() && dq.front() == i-k) dq.pop_front();
        //     while (!dq.empty() && nums[dq.back()] < nums[i])
        //         dq.pop_back();
        //     dq.push_back(i);
        //     if (i>=k-1) res.push_back(nums[dq.front()]);
        // }
        return res;
    }
};