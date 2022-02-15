class Solution {
public:
    int x;
    
    TreeNode *createTree(vector<int> &postorder,unordered_map<int,int> &mp,int i,int j){
        if(i<=j){
            int value = postorder[x--];
            
            TreeNode *root = new TreeNode(value);
            root->right = createTree(postorder,mp,mp[value]+1,j);
            root->left = createTree(postorder,mp,i,mp[value]-1);
            
            return root;
        }
        return nullptr;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        x = inorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        return createTree(postorder,mp,0,inorder.size()-1);
    }
};