class Solution {
public:
    int x = 0;
    TreeNode* createTree(vector<int>& preorder,unordered_map<int,int> &mp,int i,int j){
        if(i<=j){
            int value = preorder[x++];
            
            TreeNode *root = new TreeNode(value);
            root->left = createTree(preorder,mp,i,mp[value] - 1);
            root->right = createTree(preorder,mp,mp[value] + 1,j);
            
            return root;
        }
        return nullptr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        TreeNode *root = createTree(preorder,mp,0,preorder.size()-1);
        return root;
    }
};