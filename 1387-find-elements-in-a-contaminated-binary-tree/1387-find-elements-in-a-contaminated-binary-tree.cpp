class FindElements {
public:
    unordered_map<int,bool> mp;
    void createMAP(TreeNode *root,int x){
        if(root){
            root->val = x;
            mp[x] = true;
            createMAP(root->left,2 * x + 1);
            createMAP(root->right,2 * x + 2);
        }
    }
    FindElements(TreeNode* root) {
        createMAP(root,0);
    }
    
    bool find(int target) {
        return mp[target];
    }
};