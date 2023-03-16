class Solution {
public:
    unordered_map<int,int> mp;
    int w;
    TreeNode *build(vector<int> &post, int x,int y){
        if(x <= y){
            int val = post[w--];
            TreeNode *root = new TreeNode(val);
            
            root->right = build(post, mp[val] + 1, y);
            root->left = build(post, x, mp[val] - 1);
            
            return root;
        }
        return nullptr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        w = postorder.size() - 1;
        return build(postorder,0, postorder.size() - 1);
    }
};