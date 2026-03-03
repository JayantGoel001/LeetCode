#define pii pair<int, int>
class Trie {
public:
    vector<Trie*> children;
    int index;
    Trie() {
        this->children.resize(26, nullptr);
        index = -1;
    }
};

class Solution {
    bool isSafe(vector<vector<char>>& board, int i, int j) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[0].size() &&
               board[i][j] != '.';
    }

    void insertWord(Trie* trie, string word, int index) {
        for (auto it : word) {
            if (!trie->children[it - 'a']) {
                trie->children[it - 'a'] = new Trie();
            }
            trie = trie->children[it - 'a'];
        }
        trie->index = index;
    }

public:
    void findAllWords(Trie* trie, vector<vector<char>>& board, int i, int j,
                      vector<string>& words, vector<string>& res,
                      vector<pii>& directions) {
        if (!trie)
            return;

        if (trie->index != -1 && words[trie->index].size() > 0) {
            res.push_back(words[trie->index]);
            words[trie->index] = "";
        }

        char ch = board[i][j];
        board[i][j] = '.';

        for (auto dir : directions) {
            if (!isSafe(board, i + dir.first, j + dir.second))
                continue;

            findAllWords(
                trie->children[board[i + dir.first][j + dir.second] - 'a'],
                board, i + dir.first, j + dir.second, words, res, directions);
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        Trie* trie = new Trie();
        for (int i = 0; i < words.size(); i++) {
            insertWord(trie, words[i], i);
        }

        vector<pii> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        int n = board.size();
        int m = board[0].size();

        vector<string> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                findAllWords(trie->children[board[i][j] - 'a'], board, i, j,
                             words, res, directions);
            }
        }

        return res;
    }
};