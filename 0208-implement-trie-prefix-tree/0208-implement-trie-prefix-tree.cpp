class TrieHelper {
    public:
    vector<TrieHelper*> v;
    bool isEnd;

    TrieHelper() {
        v.resize(26, nullptr);
        isEnd = false;
    }
};
class Trie {
    TrieHelper *trie;
public:
    Trie() {
        trie = new TrieHelper();
    }
    
    void insert(string word) {
        TrieHelper *temp = trie;
        for(auto it : word) {
            if (!temp->v[it - 'a']) {
                temp->v[it - 'a'] = new TrieHelper();
            }
            temp = temp->v[it - 'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieHelper *temp = trie;
        for(auto it : word) {
            if (!temp->v[it - 'a']) {
                return false;
            }
            temp = temp->v[it - 'a'];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieHelper *temp = trie;
        for(auto it : prefix) {
            if (!temp->v[it - 'a']) {
                return false;
            }
            temp = temp->v[it - 'a'];
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