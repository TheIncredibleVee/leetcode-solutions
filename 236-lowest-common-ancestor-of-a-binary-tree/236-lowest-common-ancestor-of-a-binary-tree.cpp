/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        auto lca1 = lowestCommonAncestor(root->left, p, q);
        auto lca2 = lowestCommonAncestor(root->right, p, q);
        if(lca1 && lca2){
            return root;
        }
        if(lca2){
            return lca2;
        }
        if(lca1){
            return lca1;
        }
        return NULL;
    }
};