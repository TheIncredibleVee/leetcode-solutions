/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// class Solution {
//     private:
//         unordered_map<Node* , Node *> hash;
// public:
//     Node* cloneGraph(Node* node) {
//         if(!node){
//             return NULL;
//         }
//         if(hash.find(node) == hash.end()){
//             hash[node] = new Node(node->val);
//             for(auto x: node->neighbors){
//                 (hash[node])->neighbors.emplace_back(cloneGraph(x));
//             }
//         }
//         return hash[node];
//     }
// };




class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        unordered_map<Node*, Node* > hashset;
        Node * start = NULL;
        // Node * curr = NULL; 
        stack<Node* > st;
        st.push(node);
        unordered_map<Node *, bool> visited;
        while(!st.empty()){
            auto temp = st.top();
            st.pop();
            if(visited[temp]){
                continue;
            }
            visited[temp] = true;
            if(hashset.find(temp) == hashset.end()){
                hashset[temp] = new Node(temp->val);
            }
            vector<Node *> child = temp->neighbors;
            for(auto &x: child){
                if(hashset.find(x) == hashset.end()){
                    hashset[x] = new Node(x->val);
                }
                hashset[temp]->neighbors.emplace_back(hashset[x]);
                st.push(x);
            }

            
        }
        return hashset[node];
    }
};