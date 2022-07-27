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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return NULL;
        }
        TreeNode * root = new TreeNode(preorder[0]);
        int idx = std::find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        preorder.erase(preorder.begin());
        vector<int> leftinorder(inorder.begin(), inorder.begin() + idx);
        if(!leftinorder.empty()){
            root->left = buildTree(preorder, leftinorder);
        }
        if(idx + 1 < inorder.size()){
            vector<int> rightinorder(inorder.begin() + idx, inorder.end());
            rightinorder.erase(rightinorder.begin());
            root->right = buildTree(preorder, rightinorder);
        }
        return root;
    }
};