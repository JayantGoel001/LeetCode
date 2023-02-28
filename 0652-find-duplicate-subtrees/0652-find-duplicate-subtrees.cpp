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
    unordered_map<string, int> id;
    unordered_map<int,int> mp;
    vector<TreeNode*> v;
    
    int traverse(TreeNode *root){
        if(!root){
            return 0;    
        }
        string triplet = to_string(traverse(root->left)) + "," + to_string(root->val) + "," + to_string(traverse(root->right));
        
        if(id[triplet] == 0){
            id[triplet] = id.size() + 1;
        }
        mp[id[triplet]]++;
        
        if(mp[id[triplet]] == 2){
            v.push_back(root);
        }
        return id[triplet];
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        
        return v;
    }
};