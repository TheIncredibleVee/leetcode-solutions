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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        map<int, vector<int>> mainMap;
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            map<int, vector<int>> mp;
            mp.clear();
            while(n--){
                // cout<<level<<"\t"<<q.front().first->val<<"\t"<<q.front().second<<endl;
                auto temp = q.front();
                q.pop();
                if(mp.find(temp.second) != mp.end()){
                    mp[temp.second].push_back(temp.first->val);    
                }else{
                    mp[temp.second] = vector<int>(1, temp.first->val);
                }
                if(temp.first->left)  q.push({temp.first->left, temp.second - 1});
                if(temp.first->right) q.push({temp.first->right, temp.second + 1});
            }
            for(auto x: mp){
                sort(x.second.begin(), x.second.end());
                mainMap[x.first].insert(mainMap[x.first].end(), x.second.begin(), x.second.end());
            }
            level++;
        }
        res.reserve(mainMap.size());
        for(auto &x: mainMap){
            auto temp = x.second;
            res.push_back(temp);
        }
        return res;
    }
};