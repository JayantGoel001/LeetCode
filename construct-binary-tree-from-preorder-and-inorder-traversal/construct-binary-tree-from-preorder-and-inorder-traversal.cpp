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
    unordered_map<int,int> mp;
    int x = 0;
    TreeNode *createTree(vector<int>& preorder,int i,int j){
        if(i<=j){
            TreeNode *head = new TreeNode(preorder[x]);
            
            int index = mp[preorder[x]];
            x++;
            
            head->left = createTree(preorder,i,index-1);
            head->right = createTree(preorder,index+1,j);
            
            return head;
        }
        return nullptr;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int size = inorder.size();
        for(int i = 0;i<size;i++){
            mp[inorder[i]] = i;
        }
        
        return createTree(preorder,0,size-1);
    }
};