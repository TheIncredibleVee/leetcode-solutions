class KthLargest {
    private:
        priority_queue<int,vector<int>, greater<int>> pq;
        int total;
public:
    KthLargest(int k, vector<int>& nums) {
        int i =0;
        total = k;
        if(nums.size() == 0){
            return;
        }
        while(k--){
            pq.push(nums[i++]);
            if(i>=nums.size()){
                return;
            }
        }
        for(;i <nums.size();++i){
            if(nums[i] > pq.top()){
                pq.push(nums[i]);
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > total){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */