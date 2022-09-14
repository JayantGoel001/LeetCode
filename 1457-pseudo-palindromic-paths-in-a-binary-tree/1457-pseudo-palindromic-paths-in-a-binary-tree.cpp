class Solution {
    public:

    int res;
    void pp(TreeNode* r,vector<int> f){
        if(r==NULL) return;
        if(r->left==NULL && r->right==NULL){
            f[r->val]++;
            int c=0;
            for(int i=0; i<10; i++){
                if(f[i]%2==1) c++;
            }
            if(c<=1) res++;
            return;
        }
        f[r->val]++;
        pp(r->left,f);
        pp(r->right,f);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==NULL) return 0;
        vector<int> f(10,0);
        res=0;
        pp(root,f);
        return res;
    }
};