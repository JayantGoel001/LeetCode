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
    TreeNode* insert(TreeNode *head,int x){
        if(head){
            if(head->val > x){
                head->left = insert(head->left,x);
            }else{
                head->right = insert(head->right,x);
            }
            return head;
        }else{
            return new TreeNode(x);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *head = new TreeNode(preorder[0]);
        
        int size = preorder.size();
        for(int i=1;i<size;i++){
            insert(head,preorder[i]);
        }
        return head;
    }
};