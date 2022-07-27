class Solution {
    private:
        struct Node{
            Node* child[2];
            Node(){
                child[0] = NULL;
                child[1] = NULL;
            }
        };
        class Trie{
            private:
                Node* root;
            public:
                Trie(){
                    root = new Node();
        
                }
                void insert(int &num){
                    Node *temp = root;
                    for(int i = 31; i >= 0; --i){
                        int bit = (num >> i) & 1;
                        if(!temp->child[bit]){
                            temp->child[bit] = new Node();
                        }
                        temp = temp->child[bit];
                    }
                }
                int maxXOR(int &num){
                    int res = 0;
                    Node* temp = root;
                    for(int i = 31; i >= 0; --i){
                        int bit = (num >> i) & 1;
                        if(temp->child[1-bit]){
                            res |= (1 << i);
                            temp = temp->child[1 - bit];
                        }
                        else{
                            temp = temp->child[bit];
                        }
                    }
                    return  res;
                }
        };
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        Trie* root = new Trie();
        for(auto &x: nums){
            root->insert(x);
        }
        for(auto &x: nums){
            res = max(res, root->maxXOR(x));
        }
        return res;
    }
};