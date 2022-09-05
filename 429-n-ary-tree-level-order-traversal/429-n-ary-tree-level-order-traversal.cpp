/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            temp.reserve(n);
            for(int i = 0; i < n; ++i){
                Node* curr = q.front();
                q.pop();
                temp.emplace_back(curr->val);
                vector<Node *> child = curr->children;
                for(int j = 0; j < child.size(); ++j){
                    q.push(child[j]);
                }
            }
            res.emplace_back(temp);
        }
        return res;
    }
};