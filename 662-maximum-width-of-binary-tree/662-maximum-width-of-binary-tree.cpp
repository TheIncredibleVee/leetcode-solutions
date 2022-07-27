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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int res = 1;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int  n = q.size();
            int  start = 0;
            int mn = q.front().second;
            int end = start;
            for(int i = 0; i < n; ++i){
                auto temp = q.front().first;
                long long pos = q.front().second - mn;
                q.pop();
                if(i == n-1){
                    end = pos;
                }
                if(temp->left) q.push({temp->left, 2 * pos + 1});
                if(temp->right) q.push({temp->right, 2 * pos + 2});
            }
            res = max(res, end + 1);
        }
        return res;
    }
};