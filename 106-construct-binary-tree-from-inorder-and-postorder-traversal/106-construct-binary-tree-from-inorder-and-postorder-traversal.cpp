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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty()){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder.back());
        int idx = find(inorder.begin(), inorder.end(), postorder.back()) - inorder.begin();
        postorder.pop_back();
        vector<int> leftin(inorder.begin(), inorder.begin() + idx);
        if(idx + 1 < inorder.size()){
            vector<int> rightin(inorder.begin() + idx, inorder.end());
            rightin.erase(rightin.begin());
            root->right = buildTree(rightin, postorder);
        }
        if(!leftin.empty()){
            root->left = buildTree(leftin, postorder);
        }
        return root;
    }
};