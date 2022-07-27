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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }
        if(!p || !q){
            return false;
        }
        queue<TreeNode *> first, second;
        first.push(p);
        second.push(q);
        while(!first.empty() && !second.empty()){
            int n = first.size();
            int m = second.size();
            if(n != m){
                return false;
            }
            while(n--){
                auto temp = first.front();
                auto temp2 = second.front();
                first.pop();
                second.pop();
                if(temp->val != temp2->val){
                    return false;
                }
                bool l1 = false;
                bool l2 = false;
                bool r1 = false;
                bool r2 = false;
                if(temp->left){
                    l1 = true;
                    first.push(temp->left);
                }
                if(temp2->left){
                    l2 = true;
                    second.push(temp2->left);
                } 
                if(temp->right){
                    r1 = true;
                    first.push(temp->right);
                }
                if(temp2->right){
                    r2 = true;
                    second.push(temp2->right);
                }
                if(l1 != l2 || r1 != r2){
                    return false;
                }
            }
        }
        return first.size() == second.size();
    }
};