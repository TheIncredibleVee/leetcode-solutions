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
    int rec(TreeNode* root, int &diameter){
        if(!root){
            return 0;
        }
        int ld = 0 ;
        int rd = 0;
        int lh = rec(root->left, ld);
        int rh = rec(root->right, rd);
        diameter = max(lh + rh, max(ld, rd));
        return max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0 ;
        rec(root, res);
        return res;
    }
};