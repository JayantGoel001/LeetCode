struct Trie {
    // current node structure's serialized representation
    string serial;
    // current node's child nodes
    unordered_map<string, Trie*> children;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(
        vector<vector<string>>& paths) {
        // root node
        Trie* root = new Trie();

        for (const vector<string>& path : paths) {
            Trie* cur = root;
            for (const string& node : path) {
                if (!cur->children.count(node)) {
                    cur->children[node] = new Trie();
                }
                cur = cur->children[node];
            }
        }

        // hash table records the occurrence times of each serialized
        // representation
        unordered_map<string, int> freq;
        // post-order traversal based on depth-first search, calculate the
        // serialized representation of each node structure
        function<void(Trie*)> construct = [&](Trie* node) {
            // if it is a leaf node, then the serialization is represented as an
            // empty string, and no operation is required.
            if (node->children.empty()) {
                return;
            }

            vector<string> v;
            // if it is not a leaf node, the serialization representation of the
            // child node structure needs to be calculated first.
            for (const auto& [folder, child] : node->children) {
                construct(child);
                v.push_back(folder + "(" + child->serial + ")");
            }
            // to prevent issues with order, sorting is needed
            sort(v.begin(), v.end());
            for (string& s : v) {
                node->serial += move(s);
            }
            // add to hash table
            ++freq[node->serial];
        };

        construct(root);

        vector<vector<string>> ans;
        // record the path from the root node to the current node.
        vector<string> path;

        function<void(Trie*)> operate = [&](Trie* node) {
            // if the serialization appears more than once in the hash table, it
            // needs to be deleted.
            if (freq[node->serial] > 1) {
                return;
            }
            // otherwise add the path to the answer
            if (!path.empty()) {
                ans.push_back(path);
            }
            for (const auto& [folder, child] : node->children) {
                path.push_back(folder);
                operate(child);
                path.pop_back();
            }
        };

        operate(root);
        return ans;
    }
};