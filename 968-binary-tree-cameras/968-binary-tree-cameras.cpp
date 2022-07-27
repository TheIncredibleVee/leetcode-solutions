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
        void rec(TreeNode* root, int &res, TreeNode* parent = NULL){
            if(!root){
                return;
            }
            if(!root->left && !root->right){
                if(parent == NULL || parent->val == 1){
                    return;
                }
                parent->val = 1;
                res++;
                root->val = 1;
                return;
            }
            rec(root->left, res, root);
            rec(root->right, res, root);
            if((!root->left || root->left->val == 0) && (!root->right || root->right->val == 0) &&( !parent || parent->val == 0)){
                root->val = 1; 
                if(root->left){
                    root->left->val = 1;
                }
                if(root->right){
                    root->right->val = 1;
                }
                if(parent != NULL) parent->val = 1;
                res++;
            }
        }
public:
    
    int minCameraCover(TreeNode* root) {
        int res = 0;
        if(!root->left && !root->right){
            return 1;
        }
        rec(root, res);
        // int i = 0;
        // for(auto x: cam){
        //     if(x){
        //         // cout<<i<<endl;
        //         res++;
        //     }
        //     i++;
        // }
        return res;
    }
};