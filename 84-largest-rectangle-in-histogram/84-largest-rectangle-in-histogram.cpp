class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        int n = heights.size();
        for(int i = 0; i < n; ++i){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                int pivot = st.top();
                st.pop();
                int ps = st.empty() ? -1 : st.top();
                int curr = (i - ps - 1) * heights[pivot];
                res = max(res, curr);
            }
            st.push(i);
        }
        while(!st.empty()){
            int pivot = st.top();
            st.pop();
            int ps = st.empty() ? -1 : st.top();
            int curr = (n - ps - 1) * heights[pivot];
            res = max(res, curr);
        }
        return res;
    }
};