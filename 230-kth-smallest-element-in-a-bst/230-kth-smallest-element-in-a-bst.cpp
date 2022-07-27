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
    int kthSmallest(TreeNode* root, int k) {
        if(!root){
            return -1;
        }
        stack<TreeNode *> s;
        while(!s.empty() || root){
            while(root){
                s.push(root);
                root = root->left;
            }
            TreeNode * top = s.top();
            s.pop();
            if(k == 1){
                return top->val;
            }
            k--;
            root = top->right;
        }
        return -1;
    }
};