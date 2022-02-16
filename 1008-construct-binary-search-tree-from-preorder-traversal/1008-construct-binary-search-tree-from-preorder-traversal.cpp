class Solution {
public:
    TreeNode *insert(vector<int>& preorder,TreeNode *head,int i){
        if(head){
            if(head->val > preorder[i]) {
               head->left = insert(preorder,head->left,i);
            }else{
               head->right = insert(preorder,head->right,i);
            }
            return head;
        }else{
            return new TreeNode(preorder[i]);
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode *head = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            head = insert(preorder,head,i);
        }
        return head;
    }
};