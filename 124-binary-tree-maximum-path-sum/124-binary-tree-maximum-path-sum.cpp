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
    int rec(TreeNode *root, int &res){
        if(!root){
            return 0;
        }
        int lpath = max(0, rec(root->left, res));
        int rpath = max(0, rec(root->right, res));
        res = max(res, lpath + rpath + root->val);
        return max(lpath, rpath) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return root->val;
        }
        rec(root, res);
        return res;
    }
};













// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void printVector(vector<int> &x){
//         for(auto i: x){
//             cout<<i<<"\t";
//         }
//         cout<<endl;
//     }
//     void rec(TreeNode *root, int &res, int &currSum, vector<int> &path){
//         if(!root){
//             return;
//         }
//         currSum += root->val;
//         path.push_back(root->val);
//         rec(root->left, res, currSum, path);
//         rec(root->right, res, currSum, path);
        
//         res = max(res, accumulate(path.begin(), path.end(), 0));
//         printVector(path);
//         currSum -= root->val;
//         path.pop_back();
//     }
//     void printKPathUtil(TreeNode *root, vector<int>& path, int &res) 
//     { 
//         // empty node 
//         if (!root) 
//             return; 

//         // add current node to the path 
//         path.push_back(root->val); 

//         // check if there's any k sum path 
//         // in the left sub-tree. 
//         printKPathUtil(root->left, path, res); 

//         // check if there's any k sum path 
//         // in the right sub-tree. 
//         printKPathUtil(root->right, path, res); 

//         // check if there's any k sum path that 
//         // terminates at this node 
//         // Traverse the entire path as 
//         // there can be negative elements too 
//         int f = 0; 
//         for (int j=path.size()-1; j>=0; j--) 
//         { 
//             f += path[j]; 

//             // If path sum is k, print the path 
//             res = max(res, f);
//         } 

//         // Remove the current element from the path 
//         path.pop_back(); 
//     } 
    
    
//     int maxPathSum(TreeNode* root) {
//         int res = 0;
//         vector<int> curr;
//         int sum = 0;
//         // rec(root, res, sum, curr);
//         printKPathUtil(root, curr, res);
//         return res;
//     }
// };