class Solution {
public:
    int count = 0;
    unordered_map<long,int> mp;
    void prefixSum(TreeNode *root,int targetSum,long sum = 0L){
        if(root){
            sum += (long)root->val;
            if(sum == targetSum){
                count++;
            }
            if(mp[sum - targetSum]){
                count += mp[sum - targetSum];
            }
            mp[sum]++;
            
            prefixSum(root->left,targetSum,sum);
            prefixSum(root->right,targetSum,sum);
            
            mp[sum]--;
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefixSum(root,targetSum);
        
        return count;
    }
};