class TrieNode{
    public:
    vector<TrieNode*> v;
    bool isEnd;
    
    TrieNode(){
        v.resize(26, nullptr);
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *temp = root;
        for(auto it : word){
            if(!temp->v[it - 'a']){
                temp->v[it - 'a'] = new TrieNode();
            }
            temp = temp->v[it - 'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *temp = root;
        for(auto it : word){
            if(!temp->v[it - 'a']){
                return false;
            }
            temp = temp->v[it - 'a'];
        }
        return temp && temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for(auto it : prefix){
            if(!temp->v[it - 'a']){
                return false;
            }
            temp = temp->v[it - 'a'];
        }
        return temp;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */