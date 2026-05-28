class Trie {
public:
    Trie() : tot_(0) {
        for (int i = 0; i < N; i++) {
            memset(tr_[i], 0, sizeof(tr_[i]));
            min_len_[i] = INT_MAX;
            idx_[i] = INT_MAX;
        }
    }
    void clear() {
        for (int i = 0; i <= tot_; i++) {
            memset(tr_[i], 0, sizeof(tr_[i]));
            min_len_[i] = INT_MAX;
            idx_[i] = INT_MAX;
        }
        tot_ = 0;
    }
    void insert(const string& s, int idx) {
        int p = 0;
        if (min_len_[p] > s.length()) {
            min_len_[p] = s.length();
            idx_[p] = idx;
        }
        for (auto& ch : s) {
            int c = ch - 'a';
            if (tr_[p][c] == 0) {
                tr_[p][c] = ++tot_;
            }
            p = tr_[p][c];
            if (min_len_[p] > s.length()) {
                min_len_[p] = s.length();
                idx_[p] = idx;
            }
        }
    }
    int query(const string& s) {
        int p = 0;
        for (auto& ch : s) {
            int c = ch - 'a';
            if (tr_[p][c] != 0) {
                p = tr_[p][c];
            } else {
                break;
            }
        }
        return idx_[p];
    }

private:
    static constexpr int N = 500010, M = 26;
    int tot_;
    int tr_[N][M];
    int min_len_[N];
    int idx_[N];
};

Trie tr;

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        tr.clear();
        int n = wordsContainer.size();
        int m = wordsQuery.size();
        for (int i = 0; i < n; i++) {
            string s = wordsContainer[i];
            reverse(s.begin(), s.end());
            tr.insert(s, i);
        }

        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            string s = wordsQuery[i];
            reverse(s.begin(), s.end());
            res[i] = tr.query(s);
        }
        return res;
    }
};