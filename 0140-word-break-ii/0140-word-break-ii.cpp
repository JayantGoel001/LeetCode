class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Build the Trie from the word dictionary
        Trie trie;
        for (string word : wordDict) {
            trie.insert(word);
        }

        // Map to store results of subproblems
        unordered_map<int, vector<string>> dp;

        // Iterate from the end of the string to the beginning
        for (int startIdx = s.size(); startIdx >= 0; startIdx--) {
            // List to store valid sentences starting from startIdx
            vector<string> validSentences;

            // Initialize current node to the root of the trie
            TrieNode* currentNode = trie.root;

            // Iterate from startIdx to the end of the string
            for (int endIdx = startIdx; endIdx < s.size(); endIdx++) {
                char c = s[endIdx];
                int index = c - 'a';

                // Check if the current character exists in the trie
                if (!currentNode->children[index]) {
                    break;
                }

                // Move to the next node in the trie
                currentNode = currentNode->children[index];

                // Check if we have found a valid word
                if (currentNode->isEnd) {
                    string currentWord =
                        s.substr(startIdx, endIdx - startIdx + 1);

                    // If it's the last word, add it as a valid sentence
                    if (endIdx == s.size() - 1) {
                        validSentences.push_back(currentWord);
                    } else {
                        // If it's not the last word, append it to each sentence
                        // formed by the remaining substring
                        for (string sentence : dp[endIdx + 1]) {
                            validSentences.push_back(currentWord + " " +
                                                     sentence);
                        }
                    }
                }
            }

            // Store the valid sentences in dp
            dp[startIdx] = validSentences;
        }

        // Return the sentences formed from the entire string
        return dp[0];
    }
};