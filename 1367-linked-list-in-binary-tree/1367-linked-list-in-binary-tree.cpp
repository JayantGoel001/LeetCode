class Solution {
public:
    bool checkSubPath(ListNode* head, TreeNode* root){
        if(head && root){
            if(head->val != root->val){
                return false;
            }
            return checkSubPath(head->next,root->left) || checkSubPath(head->next,root->right);
        }else if(!head){
            return true;
        }else{
            return false;
        }
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head && root){
            if(checkSubPath(head,root)){
                return true;
            }
            return isSubPath(head, root->left) || isSubPath(head, root->right);
        }else if(!head){
            return true;
        }else{
            return false;
        }
    }
};