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
private:
    void rec(TreeNode* root, int& res, int mx){
        if(!root){
            return;
        }
        if(root->val >= mx){
            res++;
        }
        rec(root->left, res, max(mx, root->val));
        rec(root->right, res, max(mx, root->val));
    }
    
public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        rec(root, cnt, INT_MIN);
        return cnt;
    }
};