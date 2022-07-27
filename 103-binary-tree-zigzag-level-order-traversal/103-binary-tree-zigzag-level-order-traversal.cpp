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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return vector<vector<int>>();
        }
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            level.reserve(n);
            level.clear();
            while(n--){
                auto temp = q.front();
                q.pop();
                level.emplace_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(flag){
                reverse(level.begin(), level.end());
            }
            flag = !flag;
            res.emplace_back(level);
        }
        return res;
    }
};