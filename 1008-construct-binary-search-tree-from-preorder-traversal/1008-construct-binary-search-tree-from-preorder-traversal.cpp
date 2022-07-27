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
    int searchIdx(vector<int> &vec, int key, int start, int end){
        while(end >= start){
            if(vec[start] == key){
                return start;
            }
            start++;
        }
        return -1;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &preorder, int start, int end, int& preIdx){
        if(start > end){
            return NULL;
        }
        if(start == end){
            return new TreeNode(preorder[preIdx++]);
        }
        int rootVal = preorder[preIdx++];
        int findIdx = searchIdx(inorder, rootVal, start, end);
        if(findIdx == -1){
            return NULL;
        }
        TreeNode *root = new TreeNode(rootVal);
        root->left = buildTree(inorder, preorder, start, findIdx - 1, preIdx);
        root->right = buildTree(inorder, preorder, findIdx + 1, end, preIdx);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder.begin(), preorder.end());
        sort(inorder.begin(), inorder.end());
        int preIdx = 0;
        int start = 0;
        int end = preorder.size() - 1;
        TreeNode *root = buildTree(inorder, preorder, start, end, preIdx);
        return root;
    }
};