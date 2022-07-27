class Trie {
    private:
        struct Node{
            bool isEnd;
            Node *child[26];
            Node(){
                isEnd = false;
                for(int i = 0; i < 26; ++i){
                    child[i] = NULL;
                }
            }
        };
        Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int n = word.length();
        Node *temp = root;
        for(int i = 0; i < n; ++i){
            int pos = word[i] - 'a';
            if(!temp->child[pos]){
                temp->child[pos] = new Node();
            }
            temp = temp->child[pos];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        Node * temp = root;
        int n = word.length();
        for(int i = 0; i < n; ++i){
            int pos = word[i] - 'a';
            if(!temp->child[pos]){
                return false;
            }
            temp = temp->child[pos];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string word) {
        Node * temp = root;
        int n = word.length();
        for(int i = 0; i < n; ++i){
            int pos = word[i] - 'a';
            if(!temp->child[pos]){
                return false;
            }
            temp = temp->child[pos];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */