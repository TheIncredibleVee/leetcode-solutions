class NumArray {
private:
    vector<int> BIT;
    vector<int> a;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size() + 1;
        BIT = vector<int>(n + 1);
        a = vector<int>(n);
        int i = 0;
        for(int &x: nums){
            a[i] = x;
            updateDelta(++i, x);
        }
    }
    void updateDelta(int i, int delta){
        while(i < n){
            BIT[i] += delta;
            i += i & (-i);
        }
    }
    void update(int index, int val) {
        updateDelta(index + 1, val - a[index] );
        a[index] = val;
    }
    int sum(int i){
        int res = 0;
        while(i){
            res += BIT[i];
            i -= i & (-i);
        }
        return res;
    }
    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */