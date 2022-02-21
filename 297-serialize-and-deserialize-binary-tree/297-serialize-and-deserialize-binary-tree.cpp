class Codec {
public:
    string serialize(TreeNode* root) {
        if(root){
            string str = to_string(root->val);
            str.append(" ");
            str.append(serialize(root->left));
            str.append(" ");
            str.append(serialize(root->right));
            return str;
        }
        
        return "#";
    }
    int i = 0;
    TreeNode* createTree(string &data,int n){
        if(i < n){
            string res = "";
            while(i < n && data[i] != ' '){
                res += data[i++];
            }
            i++;
            if(res != "#"){
                TreeNode *root = new TreeNode(stoi(res));
                root->left = createTree(data,n);
                root->right = createTree(data,n);
                return root;
            }
        }
        return nullptr;
    }
    TreeNode* deserialize(string data) {
        return createTree(data,data.size());
    }
};