/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* rec(vector<int> &nums, int start, int end){
        cout<<start<<"\t"<<end<<endl;
        if(start > end){
            return NULL;
        }
        if(start == end){
            return new TreeNode(nums[start]);
        }
        if(start + 1 == end){
            return new TreeNode(nums[end], new TreeNode(nums[start]), NULL);
        }
        int idx = (end - start)/2;
        TreeNode * root= new TreeNode(nums[start + idx]);
        root->left = rec(nums, start, start + idx - 1);
        root->right = rec(nums, start + idx + 1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root= rec(nums, 0, nums.size() - 1);
        return root;
    }
};