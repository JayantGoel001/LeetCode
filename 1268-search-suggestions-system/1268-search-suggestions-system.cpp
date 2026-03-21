class Trie {
    public:
    vector<Trie*> child;
    vector<int> index;

    Trie() {
        child.resize(26, nullptr);
    }
};

void insert(Trie *trie, string &word, int idx) {
    for(auto it : word) {
        if (!trie->child[it - 'a']) trie->child[it - 'a'] = new Trie();
        trie = trie->child[it - 'a'];
        trie->index.push_back(idx);
    }
}

class Solution {
    vector<string> fillSearchWords(vector<string>& products, Trie *trie) {
        vector<string> res;
        for(int i = 0;i < min(3, (int)trie->index.size());i++) {
            res.push_back(products[trie->index[i]]);
        }
        return res;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        Trie *trie = new Trie();
        for(int i=0;i<products.size();i++) {
            insert(trie, products[i], i);
        }
        vector<vector<string>> res;
        for(int i=0;i<searchWord.size();i++) {
            trie = trie->child[searchWord[i] - 'a'];
            if (!trie) break;
            res.push_back(fillSearchWords(products, trie));
        }

        return res;
    }
};