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
};