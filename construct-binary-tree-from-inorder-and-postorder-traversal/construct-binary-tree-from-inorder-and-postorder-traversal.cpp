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
    int i;
    unordered_map<int,int> mp;
    TreeNode *createTree(vector<int>& postorder,int left,int right){
        if(left <= right){
            int val = postorder[i--];
            
            TreeNode *temp = new TreeNode(val);
            temp->right = createTree(postorder,mp[val]+1,right);
            temp->left = createTree(postorder,left,mp[val]-1);
            
            return temp;
        }
        return nullptr;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        this->i = postorder.size()-1;
        TreeNode *head = createTree(postorder,0,this->i);
        return head;
    }
};