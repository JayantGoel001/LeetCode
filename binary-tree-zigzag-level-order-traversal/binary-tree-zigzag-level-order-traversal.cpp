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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root){
            queue<TreeNode *> q;
            q.push(root);
            int i = 0;
            while(!q.empty()){
                int size = q.size();
                vector<int> v2;
                
                for(int j = 0;j<size;j++){
                    TreeNode *temp = q.front();
                    q.pop();
                    
                    v2.push_back(temp->val);   
                    if(temp->left){
                        q.push(temp->left);
                    }
                    if(temp->right){
                        q.push(temp->right);
                    }
                }
                if(i%2!=0){
                    reverse(v2.begin(),v2.end());
                }
                v.push_back(v2);
                i++;
            }
        }
        return v;
    }
};