class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> matchingWords;
        TrieNode* root = new TrieNode();  // Initialize the root of the Trie.

        // Insert all suffixes of each word into the Trie.
        for (const auto& word : words) {
            for (int startIndex = 0; startIndex < word.size(); startIndex++) {
                // Insert each suffix starting from index `startIndex`.
                insertWord(root, word.substr(startIndex));
            }
        }

        // Check each word to see if it exists as a substring in the Trie.
        for (auto word : words) {
            if (isSubstring(root, word)) {
                matchingWords.push_back(word);
            }
        }

        return matchingWords;
    }

private:
    class TrieNode {
    public:
        // Tracks how many times this substring appears in the Trie.
        int frequency;
        // Maps characters to their respective child nodes.
        unordered_map<char, TrieNode*> childNodes;
    };

    // Function to insert a word (or suffix) into the Trie.
    void insertWord(TrieNode* root, const string& word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            // If the character already exists as a child node, move to it.
            if (currentNode->childNodes.find(c) !=
                currentNode->childNodes.end()) {
                currentNode = currentNode->childNodes[c];
                // Increment the frequency of the node.
                currentNode->frequency++;
            } else {
                // If the character does not exist, create a new node.
                TrieNode* newNode = new TrieNode();
                // Initialize the frequency to 1.
                newNode->frequency = 1;
                // Add the new node as a child.
                currentNode->childNodes[c] = newNode;
                currentNode = newNode;  // Move to the new node.
            }
        }
    }

    // Function to check if a word exists as a substring in the Trie.
    bool isSubstring(TrieNode* root, string& word) {
        TrieNode* currentNode = root;  // Start from the root node.
        for (char c : word) {
            // Traverse the Trie following the characters of the word.
            currentNode = currentNode->childNodes[c];
        }
        // A word is a substring or a different string if its frequency in the
        // Trie is greater than 1.
        return currentNode->frequency > 1;
    }
};