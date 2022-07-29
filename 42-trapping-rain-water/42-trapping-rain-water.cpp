class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        while(left< right){
            if(height[left] < height[right]){
                leftMax = max(leftMax, height[left]);
                res += (leftMax - height[left]);
                left++;
            }else{
                rightMax = max(rightMax, height[right]);
                res += (rightMax - height[right]);
                right--;
            }
        }
        return res;
    }
    
    /*
        Alternate Soln. using stack TC O(n) and SC O(n)
    */
    // int trap(vector<int>& height) {
    //     long long res = 0;
    //     stack<int> st;
    //     int n = height.size();
    //     st.push(0);
    //     for(int i = 1; i < n; ++i){
    //         while(!st.empty() && height[st.top()] < height[i]){
    //             int curr = st.top();
    //             st.pop();
    //             int nextGreater =  i;
    //             if(st.empty()){
    //                 continue;
    //             }
    //             int prevGreater = st.top();
    //             long long w = nextGreater - prevGreater - 1;
    //             long long h = min(height[nextGreater], height[prevGreater]) - height[curr];
    //             res += h*w;
    //         }
    //         st.push(i);
    //     }
    //     return res;
    // }
};