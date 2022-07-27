class Solution {
    
public:
     int numMatchingSubseq(string s, vector<string>& words) {
         int res = 0;
         int n = s.length();
         vector<string> waiting[26];
         for(string &word : words ){
             waiting[word[0] - 'a'].push_back(word.substr(1));
         }
         for(char &x: s){
             int pos = x - 'a';
             int sz = waiting[pos].size();
             for(int i = 0; i < sz; ++i){
                 string curr = waiting[pos][i];
                 if(curr == ""){
                     res++;
                 }else{
                     int currPos = curr[0] - 'a';
                     waiting[currPos].push_back(curr.substr(1));
                 }
             }
             waiting[pos].erase(waiting[pos].begin(), waiting[pos].begin() + sz);
         }
         return res;
     }
      
/*
    Alternative Approaches
*/
    
//1. Naive
    
// private:
    // void rec(string &s, unordered_map<string, int> &st, int idx, int &res, string curr){
    //     if(idx == s.length()){
    //         if(st.find(curr)!= st.end()){
    //             res+= st[curr];
    //             st.erase(curr);
    //         }
    //         return;
    //     }
    //     rec(s, st, idx + 1, res, curr + s[idx]);
    //     rec(s, st, idx + 1, res, curr);
    // }
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
//         int res = 0;
//         unordered_map<string, int> st;
//         for(auto &x: words){
//             st[x]++;
//         }
//         rec(s, st, 0, res, "");
//         return res;
//     }
    
//2. Trie-Based Soln
    
// private:
//     struct TrieNode{
//         int end;
//         TrieNode* child[26];
//         TrieNode(){
//             for(int i = 0; i < 26; ++i){
//                 child[i] = NULL;
//                 end = 0;
//             }    
//         }
//     };
//     void insert(TrieNode* root, string &s){
//         TrieNode* node = root;
//         for(char &x: s){
//             if(!node->child[x - 'a']){
//                 node->child[x - 'a'] = new TrieNode();
//             }
//             node = node->child[x - 'a'];
//         }
//         node->end++;
//     }

// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
//         int res = 0;
//         TrieNode *root = new TrieNode;
//         for(string &word: words){
//             insert(root, word);
//         }
//         vector<TrieNode*> list[26];
//         for(int i = 0; i < 26; ++i){
//             if(root->child[i]){
//                 list[i].push_back(root->child[i]);
//             }
//         }
//         for(char &c: s){
//             int pos = c - 'a';
//             int sz = list[pos].size();
//             for(int i = 0; i < sz; ++i){
//                 TrieNode *curr = list[pos][i];
//                 res += curr->end;
//                 for(int i = 0; i < 26; ++i){
//                     if(curr->child[i]){
//                         list[i].push_back(curr->child[i]);
//                     }
//                 }
//             }
//             list[pos].erase(list[pos].begin(), list[pos].begin() + sz);
//         }
//         return res;
//     }
};