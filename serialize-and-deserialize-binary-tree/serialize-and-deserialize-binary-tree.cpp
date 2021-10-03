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
    TreeNode *createTree(string &data,int size){
        if(i < size){
            string str = "";
            while(i < size && data[i] != ' '){
                str += data[i++];
            }
            i++;
            if(str == null){
                return nullptr;
            }
            TreeNode *head = new TreeNode(stoi(str));
            
            head->left = createTree(data,size);
            head->right = createTree(data,size);
            
            return head;
        }
        return nullptr;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return createTree(data,data.size());
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));