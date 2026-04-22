struct TrieNode {
    TrieNode* child[26];
    bool isEnd;
    TrieNode() {
        memset(child, 0, sizeof(child));
        isEnd = false;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    bool dfs(string& word, int i, TrieNode* node, int cnt) {
        if (cnt > 2) return false;
        if (!node) return false;

        if (i == word.size()) {
            return node->isEnd;
        }

        int idx = word[i] - 'a';

        // no changes made
        if (node->child[idx]) {
            if (dfs(word, i + 1, node->child[idx], cnt)) return true;
        }

        // made changes
        if (cnt < 2) {
            for (int c = 0; c < 26; c++) {
                if (c == idx) continue;
                if (node->child[c]) {
                    if (dfs(word, i + 1, node->child[c], cnt + 1)) return true;
                }
            }
        }

        return false;
    }

    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        for (auto& w : dictionary) insert(w);

        vector<string> res;
        for (auto& q : queries) {
            if (dfs(q, 0, root, 0)) {
                res.push_back(q);
            }
        }
        return res;
    }
};