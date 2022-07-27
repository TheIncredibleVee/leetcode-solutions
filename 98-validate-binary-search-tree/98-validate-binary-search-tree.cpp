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
    bool isValidBST(TreeNode* root, TreeNode* mn = NULL, TreeNode* mx = NULL) {
        if(!root){
            return true;
        }
        if((root->left && root->val <= root->left->val )|| (root->right && root->right->val <= root->val)){
            return false;
        }
        if((mx && root->val >= mx->val)|| (mn && root->val <= mn->val)){
            return false;
        }
        return isValidBST(root->left, mn, root) && isValidBST(root->right, root, mx);   
    }
};