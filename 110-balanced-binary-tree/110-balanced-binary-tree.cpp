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
    bool rec(TreeNode* root, int &height){
        if(!root){
            height = 0;
            return true;
        }
        int lh = 0;
        int rh = 0;
        if(rec(root->left, lh) && rec(root->right, rh) && abs(lh - rh) <= 1){
            height = max(lh, rh) + 1;
            return true;
        }else{
            return false;
        }
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int height = 0;
        return rec(root, height);
    }
};