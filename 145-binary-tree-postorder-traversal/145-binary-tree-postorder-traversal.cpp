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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root){
            return res;
        }
        stack<TreeNode *> s;
        stack<int> op;
        s.push(root);
        while(!s.empty()){
            auto curr = s.top();
            s.pop();
            op.push(curr->val);
            if(curr->left) s.push(curr->left);
            if(curr->right) s.push(curr->right);
        }
        res.reserve(op.size());
        while(!op.empty()){
            res.emplace_back(op.top());
            op.pop();
        }
        return res;
    }
};  