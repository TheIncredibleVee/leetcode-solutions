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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        TreeNode *next;
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        q.push(root);
        depth--;
        while(!q.empty()){
            int n = q.size();
            depth--;
            for(int i = 0; i < n; ++i){
                TreeNode* curr = q.front();
                q.pop();
                if(depth == 0){
                    next = curr->left;
                    curr->left = new TreeNode(val);
                    curr->left->left = next;
                    next = curr->right;
                    curr->right = new TreeNode(val);
                    curr->right->right = next;
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(depth == 0){
                break;
            }
        }
        return root;
    }
};