class Solution {
public:
    void preorder(TreeNode *root, vector<int> &v){
        if(root){
            if(!root->left && !root->right){
                v.push_back(root->val);
            }
            preorder(root->left, v);
            preorder(root->right, v);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        preorder(root1, v1);
        preorder(root2, v2);
        
        if(v1.size() != v2.size()){
            return false;
        }
        for(int i=0;i<v1.size();i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }
        return true;
    }
};