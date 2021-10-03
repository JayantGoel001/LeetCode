/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string null = "#";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root){
            string str = to_string(root->val);
            str.append(" ");
            str.append(serialize(root->left));
            str.append(" ");
            str.append(serialize(root->right));
            return str;
        }
        return null;
    }
    int i = 0;
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(i < data.size()){
            string str = "";
            while(i < data.size() && data[i] != ' '){
                str += data[i++];
            }
            i++;
            if(str == null){
                return nullptr;
            }
            TreeNode *head = new TreeNode(stoi(str));
            
            head->left = deserialize(data);
            head->right = deserialize(data);
            
            return head;
        }
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));