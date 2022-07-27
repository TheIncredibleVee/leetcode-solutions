/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <string>  
#include <vector>  
#include <sstream>  
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        string res;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            if(temp == NULL){
                res += "null,";
                continue;
            }
            res += to_string(temp->val) + ',';
            q.push(temp->left);
            q.push(temp->right);
        }
        res.pop_back();
        cout<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = NULL;
        TreeNode *curr = NULL; 
        const char delim = ',';
        stringstream temp(data);
        string currVal;
        getline(temp, currVal, delim);
        if(currVal == "null"){
            return NULL;
        }
        int intVal = stoi(currVal);
        root = new TreeNode(intVal);
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(!getline(temp, currVal, delim)){
                break;
            }
            if(currVal != "null"){
                top->left = new TreeNode(stoi(currVal));
                q.push(top->left);
            }
            if(!getline(temp, currVal, delim)){
                break;
            }
            if(currVal != "null"){
                top->right = new TreeNode(stoi(currVal));
                q.push(top->right);
            }
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));