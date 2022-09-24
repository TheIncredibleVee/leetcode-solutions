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
    void rec(TreeNode* root, vector<int> &curr, vector<vector<int>>& res, int sum){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            if(root->val == sum){
                curr.push_back(root->val);
                res.push_back(curr);
                curr.pop_back();
                return;
            }else{
                return;
            }
        }
        curr.push_back(root->val);
        rec(root->left, curr, res, sum - root->val);
        rec(root->right, curr, res, sum - root->val);
        curr.pop_back();
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> curr;
        rec(root, curr, res, targetSum);
        return res;
    }
};