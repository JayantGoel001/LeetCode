class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int SIZE = 26;                                   // total character size
        vector<vector<int>> trie = {vector<int>(SIZE)};  // we use vector to mimic the trie tree
        vector<int> count = {0};                         // the number of words ending at node i
        for (string word : words) {  // we do not use reference here to avoid modifying the input
            sort(word.begin(), word.end());
            word.erase(unique(word.begin(), word.end()), word.end());
            if (word.size() <= 7) {  // longer words are never valid
                // insert into trie
                int node = 0;
                for (char& letter : word) {
                    int i = letter - 'a';
                    if (trie[node][i] == 0) {  // push empty node
                        trie.push_back(vector<int>(SIZE));
                        count.push_back(0);
                        trie[node][i] = trie.size() - 1;
                    }
                    node = trie[node][i];
                }
                count[node]++;
            }
        }
        // search for valid words
        function<int(int, bool, string&)> dfs = [&](int node, bool hasFirst, string& puzzle) {
            int total = hasFirst ? count[node] : 0;
            for (char& letter : puzzle) {
                int i = letter - 'a';
                if (trie[node][i]) {
                    total += dfs(trie[node][i], hasFirst || (letter == puzzle[0]), puzzle);
                }
            }
            return total;
        };
        vector<int> result;
        for (string& puzzle : puzzles) {
            result.push_back(dfs(0, false, puzzle));
        }
        return result;
    }
};