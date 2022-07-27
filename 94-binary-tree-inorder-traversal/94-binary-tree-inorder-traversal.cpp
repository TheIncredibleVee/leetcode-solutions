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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > s;
        if(!root){
            return res;
        }
        // auto curr = root;
        // while(curr || !s.empty()){
        //     while(curr){
        //         s.push(curr);
        //         curr = curr->left;
        //     }
        //     auto temp = s.top();
        //     int data = temp->val;
        //     s.pop();
        //     res.push_back(data);
        //     curr = temp->right;
        // }
        // while(!s.empty() || root){
        //     if(root){
        //         s.push(root);
        //         root = root->left; 
        //     }else{
        //         auto temp  = s.top();
        //         s.pop();
        //         res.push_back(temp->val);
        //         root = temp->right;
        //     }
        // }
        auto curr = root;
        while(curr){
            if(curr->left){
                auto temp = curr->left;
                while(temp->right && temp->right != curr){
                    temp = temp->right;
                }
                if(temp->right){
                    temp->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }else{
                    temp->right = curr;
                    curr = curr->left;
                }
            }else{
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
        return res;
    }
};