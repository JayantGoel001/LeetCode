class Solution {
private:
    struct TrieNode {
        bool isEndOfFolder;
        unordered_map<string, TrieNode*> children;
        TrieNode() : isEndOfFolder(false) {}
    };

    TrieNode* root;

    // Recursively delete all TrieNodes to prevent memory leaks
    void deleteTrie(TrieNode* node) {
        if (node == nullptr) return;
        for (auto& pair : node->children) {
            deleteTrie(pair.second);
        }
        delete node;
    }

public:
    // Constructor initializes the root of the Trie
    Solution() : root(new TrieNode()) {}

    // Clean up memory
    // A destructor to recursively delete all TrieNodes and prevent memory
    // leaks.
    ~Solution() { deleteTrie(root); }

    vector<string> removeSubfolders(vector<string>& folder) {
        // Build Trie from folder paths
        for (string& path : folder) {
            TrieNode* currentNode = root;
            istringstream iss(path);
            string folderName;

            while (getline(iss, folderName, '/')) {
                // Skip empty folder names
                if (folderName.empty()) continue;
                // Create new node if it doesn't exist
                if (currentNode->children.find(folderName) ==
                    currentNode->children.end()) {
                    currentNode->children[folderName] = new TrieNode();
                }
                currentNode = currentNode->children[folderName];
            }
            // Mark the end of the folder path
            currentNode->isEndOfFolder = true;
        }

        // Check each path for subfolders
        vector<string> result;
        for (string& path : folder) {
            TrieNode* currentNode = root;
            istringstream iss(path);
            string folderName;
            bool isSubFolder = false;

            while (getline(iss, folderName, '/')) {
                // Skip empty folder names
                if (folderName.empty()) continue;
                TrieNode* nextNode = currentNode->children[folderName];
                // Check if the current folder path is a subfolder of an
                // existing folder
                if (nextNode->isEndOfFolder && iss.rdbuf()->in_avail() != 0) {
                    isSubFolder = true;
                    break;  // Found a sub-folder
                }
                currentNode = nextNode;
            }
            // If not a sub-folder, add to the result
            if (!isSubFolder) result.push_back(path);
        }

        return result;
    }
};