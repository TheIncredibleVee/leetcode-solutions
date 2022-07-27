class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int high = n - 1;
        int low = 0;
        while(low < high){
            int currRes = (high - low)*(min(height[low], height[high]));
            res = max(res, currRes);
            if(height[low] > height[high]){
                high--;
            }else{
                low++;
            }
        }
        return res;
    }
};