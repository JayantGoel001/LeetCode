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
    int power(int x,int y){
        if(y == 0){
            return 1;
        }else{
            if(y%2 == 0){
                return power(x*x,y/2);
            }else{
                return x * power(x*x,(y-1)/2);
            }
        }
    }
    int countNodes(TreeNode* root) {
        if(root){
            TreeNode *left = root;
            TreeNode *right = root;
            
            int lH = 0;
            while(left){
                left = left->left;
                lH++;
            }
            int rH = 0;
            while(right){
                right = right->right;
                rH++;
            }
            if(lH == rH){
                return power(2,lH)-1;
            }else{
                return 1 + countNodes(root->left) + countNodes(root->right);
            }
        }else{
            return 0;
        }
    }
};