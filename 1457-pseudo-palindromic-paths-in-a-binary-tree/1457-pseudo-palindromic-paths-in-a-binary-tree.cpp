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
    void dfs(TreeNode* root, int& res, int path){
        if(!root){
            return;
        }
        path = path^(1<<root->val);
        if(!root->left && !root->right){
            if(!(path & (path - 1))){
                res++;
            }
        }
        dfs(root->left, res, path);
        dfs(root->right, res, path);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;
        int path = 0;
        dfs(root, res, path);
        return res;
    }
};