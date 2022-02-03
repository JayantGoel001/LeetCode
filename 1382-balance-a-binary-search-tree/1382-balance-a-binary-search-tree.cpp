/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    void inorder(TreeNode *root){
        if(root){
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        }
    }
    TreeNode *createBBST(int start,int end){
        if(start <= end){
            int mid = (start + end)/2;
            TreeNode *root = new TreeNode(v[mid]);
            root->left = createBBST(start,mid-1);
            root->right = createBBST(mid+1,end);
            return root;
        }
        return nullptr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return createBBST(0,v.size()-1);
    }
};