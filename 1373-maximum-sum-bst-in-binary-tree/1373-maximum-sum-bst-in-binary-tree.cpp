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
struct details{
    bool isBST;
    int mn;
    int mx;
    int sum;
    details(bool bst, int mini, int maxi, int total): isBST(bst), mn(mini), mx(maxi), sum(total){}
};
class Solution {
public:
    struct details* rec(TreeNode * root, int &res){
        if(!root){
            return new details(true,INT_MAX, INT_MIN, 0);
        }
        if(!root->left && !root->right){
            res = max(res, root->val);
            return new details(true, root->val,root->val, root->val);
        }
        details* left = rec(root->left, res);
        details* right = rec(root->right, res);
        int nodeSum = left->sum + right->sum + root->val;
        if(root->val > left->mx && root->val < right->mn && left->isBST && right->isBST){
            res = max(res, nodeSum);
            return new details(true, min(root->val, left->mn), max(root->val, right->mx), nodeSum);
        }
        return new details(false, INT_MIN, INT_MAX, nodeSum);
        
    }
    
    int maxSumBST(TreeNode* root) {
        int res= 0;
        rec(root, res);
        return res;
    }
};