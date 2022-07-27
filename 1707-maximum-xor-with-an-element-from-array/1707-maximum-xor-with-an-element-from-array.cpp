class Solution {
    private:
        struct Node{
            Node* child[2];
            Node(){
                child[0] = child[1] = NULL;
            }            
        };
        class Trie{
            private:
                Node * root;
            public:
                Trie(){
                    root = new Node();
                }
                void insert(int &num){
                    Node* temp = root;
                    for(int i = 31; i >= 0; --i){
                        bool bit = (num >> i) & 1;
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
                        bool bit = (num >> i) & 1;
                        if(temp->child[1-bit]){
                            res |= (1 << i);
                            temp = temp->child[1-bit];
                        }else{
                            temp = temp->child[bit];
                        }
                    }
                    return res;
                }
        };
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int m = nums.size();
        int n = queries.size();
        vector<int> res(n, -1);
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int,int>>> offlineQueries; 
        int index = 0;
         for(auto &it: queries) {
            offlineQueries.push_back({it[1],{it[0], index++}}); 
        }
        sort(offlineQueries.begin(), offlineQueries.end()); 
        Trie* root = new Trie();
        // int i = 0;
        // for(auto &query: queries){
        //     query.push_back(i++);
        // }
        // auto cmp = [&](vector<int> a, vector<int> b)->bool{
        //     return a[1] < b[1];
        // };
        // sort(queries.begin(), queries.end(), cmp);
        int insertPos = 0;
        for(auto &query: offlineQueries){
            int val = query.second.first;
            int maxLimit = query.first;
            int idx = query.second.second;
            while( insertPos < m && nums[insertPos] <= maxLimit){
                root->insert(nums[insertPos++]);
            }
            if(insertPos == 0){
                continue;
            }
            res[idx] = root->maxXOR(val);
        }
        return res;
    }
};